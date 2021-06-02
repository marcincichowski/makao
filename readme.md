# makao <img align="right" width="100" height="100" src="https://raw.githubusercontent.com/D4VOS/makao/f44aed212a26d2b6576557ba99a9a2ab467996c1/resources/icon.png">
A game based on the rules of the popular Polish card game - _macao_. Written in C++ using the [SFML] library.

The game was made for a university project.

## Rules
Game rules
Can play for 2 to 4 people.

### The course of the game

The game is played with all cards in the deck except the Joker. At the beginning, each player is dealt 5 cards. Put the rest of the cards aside, revealing one, visible to all players (if it is 2, 3 or the king of hearts, the war is activated). The move is to play your cards with one that suits you
face-up and face-up on the table with a color or face. He can also put a card with a different figure but of the color of the card lying on the table. If a player does not have a suitable card or does not want to give away one of his cards, then he draws a new card from the discarded pile. The next player must deal a card that matches the color or face of the top card.

__The first player to lay down all their cards wins.__

If the deck from which we draw cards runs out, then shuffle the pile of cards and put them back in the deck, placing the last player on top of the pile.

### Function cards
- king of hearts - the next player takes five cards (he can also put the queen of hearts to block the king) and start a war.

- 2 and 3 - the next player draws a number of cards equal to the value of the card. However, if he has a card of the same value or suit (but 2, 3, or King of hearts *), he may play it, then the next player must draw the sum of the values ​​of the cards on the table, unless he also has a matching 2, 3, or King of hearts).

- 4 - the next player waits one turn, or if he has, he places 4, then the next player waits two turns, etc.

- Jack (of any color) - the player can request cards from 5 to 10

- as - request for a color change by the lecturer. If the next player has a different ace, he may play it by requesting a different color.

- queen of hearts - by losing the queen, we cancel the functional card placed by the previous player (for example, it can remove the war status or reset requests and cancel the action of four)

## Requirements
- [SFML v2.5.1][SFMLdownload]
- G++

[SFML]:<https://www.sfml-dev.org>
[SFMLdownload]:<https://www.sfml-dev.org/download/sfml/2.5.1>

