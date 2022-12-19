#include <iostream> 
#include <vector>
#include <cstring> 
#include <clocale>
using namespace std;

const char EMPTY = '-';
const int BOARD_SIZE = 3;
const int BOARD_CENTER = 4;

struct Player {
    char Character;
    std::string PlayerName;
};

char win = EMPTY;
//char PlayerName1[80], PlayerName2[80];
Player players[2];
char cells[9] = { '-','-','-','-','-','-','-','-','-' };


enum class FieldValue : size_t {
    Empty,
    ValueO,
    ValueX
};

struct Field {
    size_t const id;
    FieldValue value;
};

struct Board {
    //vector<vector<Field>> fields{3, vector<Field>{3, Field{FieldValue}}};
    vector<vector<Field>> fields{{Field{1, FieldValue::Empty}, Field{2, FieldValue::Empty}, Field{3, FieldValue::Empty}},
                                 {Field{4, FieldValue::Empty}, Field{5, FieldValue::Empty}, Field{6, FieldValue::Empty}},
                                 {Field{7, FieldValue::Empty}, Field{8, FieldValue::Empty}, Field{9, FieldValue::Empty}}};

    void printIDs() const {
        for (auto const& item1 : fields) {
            for (auto const& item2 : item1) {
               cout << "-" << item2.id << "-";
            }
            cout << endl;
        }
    }
} Board;

void show_cells() {
    system("cls");

    cout << "Cell number: \n";
    // cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << endl;
    // cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << endl;
    // cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << endl;
    Board.printIDs();

    cout << "Current state (\"---\" - empty cell):\n" << endl;
    cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
    cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
    cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;

    // Board.printValues();
}
bool isCellInBounds(int cell) {
    return cell <= 9 && cell >= 1;
}

bool isCellEmpty(int cell) {
    return cells[cell - 1] == EMPTY;
}

int inputCell(std::string name) {
    // if (num == 1) cout << PlayerName1;
    // else cout << PlayerName2;
    cout << name;

    int cell;
    cout << ",input cell number,make you step!:";
    cin >> cell;
  
       
    while (!isCellInBounds(cell) && !isCellEmpty(cell)) {
        cout << "Input correct cell number ( 1-9 ) for empty ( --- ) cell for making step:";
        cin >> cell;
        cout << "\n";
    }

    return cell;
}

void setChar(char Character, int cell) {
    // if (num == 1) cells[cell - 1] = 'X';
    // else cells[cell - 1] = 'O';
    cells[cell - 1] = Character;
}

void make_move(int num) {
    int cell = inputCell(players[num].PlayerName);
    
    setChar(players[num].Character, cell);
}

bool isVertical(int i) {
    return cells[i * BOARD_SIZE] == cells[i * BOARD_SIZE + 1] && cells[i * BOARD_SIZE + 1] == cells[i * BOARD_SIZE + 2];
}

bool isHorizontal(int i) {
    return cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6];
}

bool isDiagonal() {
  return (cells[2] == cells[4] && cells[4] == cells[6]) || (cells[0] == cells[4] && cells[4] == cells[8]);
}

char check()
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (isVertical(i)) {
            return cells[i]; 
        }
        if (isHorizontal(i)) {
            return cells[i];
        }
    }
    if (isDiagonal())
        return cells[BOARD_CENTER]; 
    return EMPTY; 
}

void result() {
    if (win == 'X')
        cout << PlayerName1 << "You win! " << PlayerName2 << " but you loose..." << endl;
    else if (win == 'O') cout << PlayerName2 << "You win!  " << PlayerName1 << " but you loose..." << endl;

}

int main(int argc, char** argv) {
 
    do {
        cout << "Input name of first player: ";
        // gets_s(PlayerName1,80);
        cin >> PlayerName1;

        cout << "Input name of second player: ";
        // gets_s(PlayerName2,80);
        cin >> PlayerName2;
        cout << "\n";
    //} while (!strcmp(PlayerName1, PlayerName2));
    } while (PlayerName1 == PlayerName2);
    
    show_cells();

    for (int move = 1; move <= 9; move++) {
        // if (move % 2) make_move(1); 
        // else make_move(2);
        make_move(move % 2);

        show_cells();
        
        if (move >= 5)
        {
            win = check();
            if (win != '-')
                break;
        }
  
    }

    result();
   
    return 0;
}