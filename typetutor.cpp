#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <limits>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<string> words = {
    "reticent", "leverage", "collaboration", "efficient", "emergency",
    "enthusiasm", "observation", "organization", "outstanding", "overcome",
    "platform", "pollution", "politician", "practice", "bracket", "hyphen",
    "scissors", "secondary", "secretary", "separation", "expansive",
    "software", "specialist", "barricade", "brandish", "concoction",
    "diminish", "engross", "grueling", "imperious", "luminous", "malleable",
    "meticulous", "obscure", "persistent", "replenish", "sabotage", "stamina",
    "uncanny", "versatile", "vulnerable", "fathom", "cliche", "tedious",
    "perfunctory", "reminiscent", "insatiable", "articulate", "dyslexic",
    "novice", "exasperated", "superlative", "chronic"
};

vector<string> sentences = {
    "This restaurant has the best kitchen in town",
    "House prices have gone up this year",
    "I went to football practice",
    "England has the best language schools",
    "I don�t think you should go out with him",
    "I haven�t been invited",
    "You�re not allowed to use your phone here",
    "She�s an excellent photographer",
    "Her paintings are works of art",
    "Cutting down on sugar will help you lose weight",
    "Doing more exercise will help you",
    "I want to talk to Prince Harry when I�m in England",
    "Zack has skipped school on many occasions",
    "He�s failed his French test",
    "I�ve done a pranic healing course",
    "You didn�t tell me you wanted to come",
    "We won�t be taking you with us",
    "Plenty of tourists visit the area in summer",
    "Pet pigs are cleaner than dogs",
    "They�re completely loyal to their owners",
    "You�ll have to focus on your immediate surroundings",
    "Most significantly, avoid eye-contact at all costs",
    "How can I put this?",
    "Misunderstandings can be highly destructive",
    "Don�t be unsociable",
    "I�m going to Janet�s party at the weekend",
    "It�s hard to say the same thing",
    "You might want to change a few things",
    "Meanwhile, I was enjoying my skype lessons",
    "Anyhow, I�ve just decided to learn Russian next",
    "He will abjure his allegiance to the king",
    "I like cats of the Turkish Van breed",
    "I ate a delicious hamburger",
    "The elephant likes painting",
    "Charlie was next to Anne",
    "Remember the rules from before",
    "Who is playing the trumpet?"
};

void playLevel(char level, int duration) {
    int correctCount = 0;
    int mistakeCount = 0;
    int totalEntries = 0;

    auto start = high_resolution_clock::now();
    auto end = start + seconds(duration);

    while (high_resolution_clock::now() < end) {
        string target;
        if (level == '1') {
            target = string(1, 'a' + rand() % 26);
        } else if (level == '2') {
            target = words[rand() % words.size()];
        } else if (level == '3') {
            target = sentences[rand() % sentences.size()];
        }

        cout << "Type: " << target << endl;
        string input;
        getline(cin, input);

        if (input == target) {
            correctCount++;
        } else {
            mistakeCount++;
        }
        totalEntries++;
    }

    auto elapsed = duration_cast<seconds>(high_resolution_clock::now() - start).count();
    double averageSpeed = (double)totalEntries / elapsed * 60.0;  // entries per minute

    cout << "\nTime's up!\n";
    cout << "Correct: " << correctCount << endl;
    cout << "Mistakes: " << mistakeCount << endl;
    cout << "Average speed: " << averageSpeed << " entries per minute\n";
}

int main() {
    srand(time(0));
    string username;
    cout << "Enter your username: ";
    getline(cin, username);

    char choice;
    do {
        cout << "Welcome " << username << " to the Typing Tutor Game!" << endl;
        cout << "Choose a level:" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Hard" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice) {
            case '1':
                playLevel(choice, 60);
                break;
            case '2':
                playLevel(choice, 60);
                break;
            case '3':
                playLevel(choice, 60);
                break;
            case '4':
                cout << "Goodbye " << username << "!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}

