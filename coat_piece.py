#import numpy as np
import random

SUITS = ['H', 'S', 'D', 'C']    # H-Hearts, S-Spades, D-Diamond, C-Clubs
NUMBER_OF_PLAYERS = 4
NUMBER_OF_HANDS = 13


class Card:
    def __init__(self, num, suit):
        self.number = num           # The number on the card (2 - 14) [11-Jack, 12-Queen, 13-King, 14-Ace]
        self.suit = suit
        self.player = None

    def set_player(self, player):
        self.player = player


class Player:
    def __init__(self, num):
        self.number = num
        self.card_list = []

    def define_trump(self):
        max_suit = None
        suit_count = {"H": 0, "S": 0, "D": 0, "C": 0}
        for card in self.card_list[0:5]:
            suit_count[card.suit] += card.number
        max_num = 0
        print(suit_count)
        for suit in suit_count:
            if suit_count[suit] >= max_num:
                max_num = suit_count[suit]
                max_suit = suit
        return max_suit

    def playcard(self, active_pile):
        raise NotImplementedError


class Team:
    def __init__(self):
        self.player_list = []
        self.hands_made = 0

    def add_player(self, player):
        self.player_list.append(player)


class Board:
    def __init__(self):
        self.trump = None
        self.discard_pile = []
        self.active_cards = []
        self.deck = []
        self.current_player = None

    def shuffle(self):
        random.shuffle(self.deck)

    def generate_cards(self):
        deck = []
        for suit in SUITS:
            for rank in range(2,15,1):
                card = Card(rank, suit)
                deck.append(card)
        return deck

    def reset(self):
        self.trump = None
        self.discard_pile = []
        self.active_cards = []
        self.deck = self.generate_cards()

    def distribute(self, players, trump_player, teams):
        current_player = trump_player
        # Distributing the cards in order (with trump_player being first)
        for i in range(4):

            # Adding trump_player and the next to next player in team_a or teams[0] (even)
            # Adding rest of the players or teams[1] (odd)
            if i % 2 == 0:
                teams[0].add_player(players[current_player])
            else:
                teams[1].add_player(players[current_player])
            players[current_player].card_list = self.dealer(current_player)
            current_player = self.next_player(current_player)

        # Setting the card to its owner
        for player in players:
            for card in player.card_list:
                 card.set_player(player.number)

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


class Game:
    def __init__(self):
        self.winner = None

    def check_winner(self):
        raise NotImplementedError

def game_init():
    game = Game()
    players = []
    for i in range(4):
        player = Player(i)
        players.append(player)


    board = Board()
    board.reset()
    board.shuffle()


    # Who will play first and define trump
    trump_player = random.randint(0, 3)

    teams = []
    team_a = Team()  # Trump team
    team_b = Team()  # Opposing team
    teams.append(team_a)
    teams.append(team_b)

    board.distribute(players, trump_player, teams)

    board.current_player = trump_player

    print(trump_player)

    # Check for trump
    # for card in players[trump_player].card_list[0:5]:
    #     print("card: {},{} ,Player-{}".format(card.number, card.suit, card.player))
    board.trump = players[trump_player].define_trump()

    # Check distribution in teams
    # for team in teams:
    #     for player in team.player_list:
    #         for card in player.card_list[0:5]:
    #             print("card: {},{} ,Player-{}".format(card.number, card.suit, card.player))

    print(board.trump)


    # Game play  13 hands

    for hand in range(NUMBER_OF_HANDS):
        for turn in range(NUMBER_OF_PLAYERS):
            players[board.current_player].playcard(board.active_cards)  # Player will select a card from his card list
            board.current_player = board.next_player(board.current_player)

        # check hand winner

if __name__ == '__main__':
    game_init()