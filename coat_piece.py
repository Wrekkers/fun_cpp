#import numpy as np
import random

SUITS = ['H', 'S', 'D', 'C']


class Card:
    def __init__(self, num, suit):
        self.number = num
        self.suit = suit


class Game:
    def __init__(self):
        self.winner = None


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

    def playcard(self):
        raise NotImplementedError


class Board:
    def __init__(self):
        self.trump = None
        self.discard_pile = []
        self.active_cards = []
        self.deck = []

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

    def distribute(self, players):
        players[0].card_list = self.deck[0:5] + self.deck[20:24] + self.deck[36:40]
        players[1].card_list = self.deck[5:10] + self.deck[24:28] + self.deck[40:44]
        players[2].card_list = self.deck[10:15] + self.deck[28:32] + self.deck[44:48]
        players[3].card_list = self.deck[15:20] + self.deck[32:36] + self.deck[48:52]
        self.deck = []


def game_init():
    game = Game()
    players = []
    for i in range(1, 5, 1):
        player = Player(i)
        players.append(player)


    board = Board()
    board.reset()
    board.shuffle()
    board.distribute(players)

    # Who will play the trump
    trump_player = random.randint(0, 3)
    print(trump_player)
    for card in players[trump_player].card_list[0:5]:
        print("card: {},{}".format(card.number, card.suit))
    board.trump = players[trump_player].define_trump()

    print(board.trump)


if __name__ == '__main__':
    game_init()