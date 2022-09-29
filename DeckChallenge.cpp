#include <cstdio>
#include <string>
#include <vector>
#include <time.h>

const char suits[4] = { 's', 'h', 'c', 'd' };
const char ranks[13] = { 'A', '2','3','4','5','6','7','8','9','T','J', 'Q', 'K' };

class Card {
public:
    char rank;
    char suit;
};

class Deck {
public:
    void shuffle_deck() {
        srand(time(0));
        for (int i = 0; i < cards.size() / 2; i++) {
            int randomInd = rand() % (numOfCards - (i + 1)) + (i + 1);
            std::swap(cards[i], cards[randomInd]);
        }
    }
    int remaining() {
        return numOfCards;
    };
    int deck_size() {
        return deckSize;
    };
    const Card* deck() {
        return &cards.front();
    };
    const Card& deal_card() {
        if (remaining() > 0) {
            Card nextCard = cards.front();
            --numOfCards;
            cards.erase(cards.begin());
            return nextCard;
        }
        else {
            puts("No cards left in the deck");
            exit;
        }
    }
    void newDeck() {
        if (deckSize < 10) {
            ++deckSize;
            numOfCards += 52;
            Card cardToAdd;
            for (char suit : suits) {
                for (char rank : ranks) {
                    cardToAdd.rank = rank;
                    cardToAdd.suit = suit;
                    cards.push_back(cardToAdd);
                }
            }
        }
        else { 
            puts("You have reached the maximum number of decks."); 
        }
    };
    void newDeck(int n) {
        if (deckSize + n < 10) {
            for (int i = 0; i < n; i++) {
                ++deckSize;
                numOfCards += 52;
                Card cardToAdd;
                for (char suit : suits) {
                    for (char rank : ranks) {
                        cardToAdd.rank = rank;
                        cardToAdd.suit = suit;
                        cards.push_back(cardToAdd);
                    }
                }
            }
        }
        else {
            puts("You have reached the maximum number of decks.");
        }
    }
    std::vector<Card> getCards() {
        return cards;
    }
private:
    int deckSize = 0;
    int numOfCards = 0;
    std::vector<Card> cards;
};

int main()
{
    Deck deck;
    deck.newDeck();
    for (Card card : deck.getCards()) {
        printf("%c%c ", card.rank, card.suit);
    }
    puts("");

    printf("Deck Size: %d\n", deck.deck_size());

    Card dealCard1 = deck.deal_card();
    printf("Deal Card: %c%c\n", dealCard1.rank, dealCard1.suit);
    dealCard1 = deck.deal_card();
    printf("Deal Card: %c%c\n", dealCard1.rank, dealCard1.suit);

    printf("Remaining Cards: %d\n", deck.remaining());

    printf("Address of first card in the deck: %p\n", deck.deck());

    printf("First card of the deck: %c%c\n",  deck.deck()->rank, deck.deck()->suit);

    deck.shuffle_deck();
    puts("Shuffled Card Deck:");
    for (Card card : deck.getCards()) {
        printf("%c%c ", card.rank, card.suit);
    }
    puts("");

    dealCard1 = deck.deal_card();
    printf("Deal Card: %c%c\n", dealCard1.rank, dealCard1.suit);

    printf("First card of the deck: %c%c\n", deck.deck()->rank, deck.deck()->suit);

    printf("Remaining Cards: %d\n", deck.remaining());

    return 0;
}
