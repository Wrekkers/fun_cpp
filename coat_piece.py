#import numpy as np
import random

SUITS = ['H', 'S', 'D', 'C']    # H-Hearts, S-Spades, D-Diamond, C-Clubs
NUMBER_OF_PLAYERS = 4
NUMBER_OF_HANDS = 13


class Card:
    def __init__(self, num, suit):
        self.number = num           # The number on the card (2 - 14) [11-Jack, 12-Queen, 13-King, 14-Ace]
        self.suit = suit


class Player:
    def __init__(self, num):
        self.number = num
        self.card_list = []
        self.discard_pile = []      # Knowledge of

    def define_trump(self, manual):
        max_suit = None
        if manual and self.number == 0:
            first_five = ""
            for card in self.card_list[0:5]:
                first_five = first_five + " ({},{}) ".format(card.number, card.suit)
            print("Choose Trump from : {}".format(first_five))
            while max_suit not in ['H', 'S', 'D', 'C']:
                max_suit = input("Enter (H/S/D/C) :").upper()

        else:
            suit_count = {"H": 0, "S": 0, "D": 0, "C": 0}
            for card in self.card_list[0:5]:                # Select the highest sum of suit in first 5 cards
                suit_count[card.suit] += card.number
            max_num = 0
            for suit in suit_count:
                if suit_count[suit] >= max_num:
                    max_num = suit_count[suit]
                    max_suit = suit
        return max_suit

    def print_card_list(self, card_list):
        print_card_list = ""
        for i, card in enumerate(card_list):
            print_card_list = print_card_list + " {}:({},{}) ".format(i, card.number, card.suit)

        return print_card_list

    def get_suited_card_list(self, suits):
        card_list = []
        for card in self.card_list:
            if card.suit in suits:
                card_list.append(card)
        return card_list

    def play_manual(self, active_pile, player_order):
        if not active_pile:
            legal_card_list = self.get_suited_card_list(SUITS)
        else:
            active_suit = active_pile[player_order[0]].suit
            legal_suits = [active_suit]
            legal_card_list = self.get_suited_card_list(legal_suits)
            if not legal_card_list:
                legal_card_list = self.get_suited_card_list(SUITS)

        print("CARDS PLAYED: ")
        for playa in player_order[:-1]:         # Do not print cards of the latest added player
            print("Player {}: ({},{})".format(playa, active_pile[playa].number, active_pile[playa].suit))

        c_list = self.print_card_list(legal_card_list)
        print("YOUR HAND: {}".format(c_list))

        idx = len(legal_card_list)
        legal_move = [x for x in range(len(legal_card_list))]
        while idx not in legal_move:
            idx = int(input("Enter the index of the legal playable card list: "))

        selected_card = legal_card_list[idx]
        active_pile[self.number] = selected_card
        self.card_list.pop(self.card_list.index(selected_card))


    # This function defines the rules of playing coat piece
    def play_legal_card_random(self, active_pile, trump, first_player):

        selected_card = None
        if not active_pile:
            card_num = random.randint(0, len(self.card_list) - 1)  # random card selector
            selected_card = self.card_list[card_num]
        else:
            active_suit = active_pile[first_player].suit
            legal_suits = [active_suit]
            legal_card_list = self.get_suited_card_list(legal_suits)
            if legal_card_list:
                card_num = random.randint(0, len(legal_card_list) - 1)  # random card selector from active suit
                selected_card = legal_card_list[card_num]
            else:
                legal_suits.append(trump)
                legal_card_list = self.get_suited_card_list(legal_suits)
                if legal_card_list:
                    card_num = random.randint(0, len(legal_card_list) - 1)  # random card selector from trump
                    selected_card = legal_card_list[card_num]
                else:
                    card_num = random.randint(0, len(self.card_list) - 1)  # random card selector from whole list
                    selected_card = self.card_list[card_num]

        active_pile[self.number] = selected_card
        self.card_list.pop(self.card_list.index(selected_card))


class Team:
    def __init__(self):
        self.player_list = [] # Will contain the list of player numbers
        self.hands_made = 0

    def add_player(self, player_num):
        self.player_list.append(player_num)

    def check_player(self, player_num):
        return player_num in self.player_list


class Board:
    def __init__(self):
        self.trump = None
        self.discard_pile = []
        self.active_pile = {}
        self.deck = []
        self.current_player = None
        self.player_order = []

    def shuffle(self):
        random.shuffle(self.deck)

    def generate_cards(self):
        self.deck = []
        for suit in SUITS:
            for rank in range(2, 15, 1):
                card = Card(rank, suit)
                self.deck.append(card)

    def reset(self):
        self.trump = None
        self.discard_pile = []
        self.active_pile = {}
        self.player_order = []
        self.generate_cards()

    def distribute(self, players, trump_player, teams):
        current_player = trump_player
        # Distributing the cards in order (with trump_player being first)
        for i in range(4):

            # Adding trump_player and the next to next player in team_a or teams[0] (even)
            # Adding rest of the players or teams[1] (odd)
            if i % 2 == 0:
                teams[0].add_player(players[current_player].number)
            else:
                teams[1].add_player(players[current_player].number)
            players[current_player].card_list = self.dealer(current_player)
            current_player = self.next_player(current_player)

        self.deck = []

    def dealer(self, player):
        # Switch case for distributing the cards according to 5, 4 , 4 rule
        dealer = {
            0: self.deck[0:5] + self.deck[20:24] + self.deck[36:40],
            1: self.deck[5:10] + self.deck[24:28] + self.deck[40:44],
            2: self.deck[10:15] + self.deck[28:32] + self.deck[44:48],
            3: self.deck[15:20] + self.deck[32:36] + self.deck[48:52]
        }
        return dealer.get(player, "Invalid player number")

    def next_player(self, current_player):
        if current_player == 3:
            return 0
        else:
            return current_player + 1

    def check_hand_winner(self):
        high_card = self.active_pile[self.player_order[0]]  # This will store the highest card of active suit
        high_player = self.current_player
        active_suit = self.active_pile[0].suit

        high_card_trump = None
        high_player_trump = None
        if active_suit == self.trump:
            high_player_trump = self.current_player
            high_card_trump = high_card  # This will store highest trump card if trump is played

        for playa, card in self.active_pile.items():
            if card.suit == self.trump:
                if high_card_trump is None or card.number > high_card_trump.number:
                    high_card_trump = card
                    high_player_trump = playa
            elif card.suit == active_suit:
                if card.number > high_card.number:
                    high_card = card
                    high_player = playa

        if high_card_trump is None:
            return high_player
        else:
            return high_player_trump

    def clear_board(self):
        self.discard_pile = self.discard_pile + [card for key, card in self.active_pile.items()]
        self.active_pile = {}
        self.player_order = []


class Game:
    def __init__(self):
        self.winner = None
        self.manual = False
        self.manual_player = None

    def set_manual(self):
        manual = input("Do you want to play the game? (Y/N)")
        if manual.upper() == 'Y':
            self.manual = True
            self.manual_player = 0
            print("You are assigned - Player 0")

    def check_winner(self, teams):
        if teams[0].hands_made > teams[1].hands_made:
            self.winner = "Team A"
        else:
            self.winner = "Team B"

    def game_init(self, players, board, teams):

        board.reset()
        board.shuffle()

        # Who will play first and define trump
        trump_player = random.randint(0, 3)

        board.distribute(players, trump_player, teams)

        board.current_player = trump_player

        print("Player {} will play first".format(trump_player))

        # Check for trump
        # for card in players[trump_player].card_list[0:5]:
        #     print("card: {},{} ,Player-{}".format(card.number, card.suit, card.player))
        board.trump = players[trump_player].define_trump(self.manual)

        # Check distribution in teams
        # for team in teams:
        #     for player in team.player_list:
        #         for card in player.card_list[0:5]:
        #             print("card: {},{} ,Player-{}".format(card.number, card.suit, card.player))

        print("TRUMP : {}".format(board.trump))

    def play_game(self, players, board, teams):
        # Game play  13 hands

        for hand in range(NUMBER_OF_HANDS):
            for turn in range(NUMBER_OF_PLAYERS):
                board.player_order.append(board.current_player)
                if self.manual and board.current_player == 0:
                    players[board.current_player].play_manual(board.active_pile, board.player_order)
                else:
                    players[board.current_player].play_legal_card_random(board.active_pile, board.trump, board.player_order[0])  # Player will select a card from his card list
                board.current_player = board.next_player(board.current_player)

            """ ############ PRINT STATEMENTS ################ """
            print("Hand {}:".format(hand+1))
            for i in range(NUMBER_OF_PLAYERS):
                card = board.active_pile[board.player_order[i]]
                print("Player {}: Card ({},{})".format(board.player_order[i], card.number, card.suit))
            """ ############################################## """

            winner_player = board.check_hand_winner()     # check hand winner
            board.current_player = winner_player   # The winner will play the first turn in next hand

            if teams[0].check_player(winner_player):  # Adding score to the winning team
                teams[0].hands_made += 1
            else:
                teams[1].hands_made += 1

            board.clear_board()     # Clearing the active game pile for next hand

            print("Winner: Player {}, Team A: {}, Team B: {}".format(winner_player, teams[0].hands_made, teams[1].hands_made))
            print("==============================================")
        self.check_winner(teams)

        print("Winning Team: {}".format(game.winner))


if __name__ == '__main__':
    game = Game()
    players = []
    for i in range(4):
        player = Player(i)
        players.append(player)

    board = Board()

    teams = []
    team_a = Team()  # Trump team
    team_b = Team()  # Opposing team
    teams.append(team_a)
    teams.append(team_b)

    game.set_manual()

    game.game_init(players, board, teams)
    game.play_game(players, board, teams)