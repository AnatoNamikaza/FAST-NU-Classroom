#include iostream
#includevector

using namespace std;

class Connect4State {
public
    char State[6][7];  A 6 x 7 array to hold discs placed by players
    char PlayerSign[2];
    int MovingPlayer;
    int Winner;  Winner = -1 means game is not over yet and Winner = PlayerID {0 or 1} of winner or 3 if game results in a draw

    int PossibleMoves[7];  Hold largest empty row position for each column
    vectorint Moves;

    int validCol() {
        int count = 0;
        for (int i = 0; i  7; i++)
            if (PossibleMoves[i] = 0)count++;
        return count;
    }

    bool CheckGameOver(int Move) {
        int i = 0;
        for (; i  6 && State[i][Move] == '.'; i++);

        for (int s = i + 1, count = 0; s  6; s++)
        {
            if (State[i][Move] == State[s][Move]) count++;
            else break;

            if (count == 3)
            {
                if (State[i][Move] == 'O')  Winner = 0;
                else if (State[i][Move] == 'X') Winner = 1;
                return false;
            }
        }

        for (int s = 0, count = 0; s  7; s++)
        {
            if (State[i][Move] == State[i][s]) count++;
            else count = 0;

            if (count == 4)
            {
                if (State[i][Move] == 'O')  Winner = 0;
                else if (State[i][Move] == 'X') Winner = 1;
                return false;
            }
        }

        for (int x = 0; x  3; x++)
            for (int y = 0; y  4; y++)
                if ((State[x][y] == State[x + 1][y + 1] == State[x + 2][y + 2] == State[x + 3][y + 3])
                     (State[x + 3][y] == State[x + 2][y + 1] == State[x + 1][y + 2] == State[x][y + 3]))
                {
                    if (State[i][Move] == 'O')  Winner = 0;
                    else if (State[i][Move] == 'X') Winner = 1;
                    return false;
                }


        for (int i = 0; i  6; i++)
            for (int j = 0; j  7; j++)
                if (State[i][j] == '.')
                    return false;

        Winner = 3;
        return false;
    }

    Connect4State(char FirstPlayer = 'O', char SecondPlayer = 'X', int StartingPlayer = 0) {

        if (1  StartingPlayer  StartingPlayer  0)
            StartingPlayer = 0;
        MovingPlayer = StartingPlayer;

        PlayerSign[0] = FirstPlayer;
        PlayerSign[1] = SecondPlayer;

        cout  First   FirstPlayer  tSecond    SecondPlayer  endl;
        Winner = -1;

        for (int c = 0; c  7; c++) {
            PossibleMoves[c] = 5;  Largest empty row in each column
            for (int r = 0; r  6; r++)
                State[r][c] = '.';  Initially each cell has null char
        }
    }

    bool ValidateMove(int Move) {
        if (Winner = 0)
            return false;
        if (6  Move  Move  0)
            return false;
        if (PossibleMoves[Move]  0)
            return false;
        return true;
    }

    double Evaluate(int Row, int Col) {
        int t_win_ = 0;

        Vertical Win Check
        for (int i1 = Row - 1, i2 = Row + 1, s1 = 0, c = 0, win_ = 0; c  3; c++)
        {
            if (i1 = 0)
            {
                if (State[i1][Col] == '.') win_++;
                i1--;
            }
            if (i2 = 5 && s1 == 0)
            {
                if (State[i2][Col] == State[Row][Col]) win_++;
                else s1 = -1;
                i2++;
            }
            if (win_ = 3)
            {
                t_win_++;
                break;
            }
        }

        Horizontal Win Check
        for (int i1 = Col - 1, i2 = Col + 1, s1 = 0, s2 = 0, c = 0, win_ = 0; c  3; c++)
        {
            if (i1 = 0 && s1 == 0)
            {
                if (State[Row][i1] == '.'  State[Row][i1] == State[Row][Col]) win_++;
                else s1 = -1;
                i1--;
            }
            if (i2 = 6 && s2 == 0)
            {
                if (State[Row][i2] == '.'  State[Row][i2] == State[Row][Col]) win_++;
                else s2 = -1;
                i2++;
            }

            if (win_ = 3)
            {
                t_win_++;
                break;
            }
        }

        Diagonal Win Check
        for (int
            i1 = Row - 1, j1 = Col - 1,  Top-Left
            i2 = Row + 1, j2 = Col + 1,  Bottom-Right
            i3 = Row - 1, j3 = Col + 1,  Top-Right
            i4 = Row + 1, j4 = Col - 1,  Bottom-Left
            s1 = 0, s2 = 0, s3 = 0, s4 = 0,
            c = 0, win_1 = 0, win_2 = 0; c  3; c++)
        {
            Front Slash
            if (i1 = 0 && j1 = 0 && s1 == 0)
            {
                if (State[i1][j1] == State[Row][Col]  State[i1][j1] == '.') win_1++;
                else s1 = -1;
                i1--, j1--;
            }
            if (i2 = 5 && j2 = 6 && s2 == 0)
            {
                if (State[i2][j2] == State[Row][Col]  State[i2][j2] == '.') win_1++;
                else s2 = -1;
                i2++, j2++;
            }
            if (win_1 = 3)
            {
                t_win_++;
                s1 = s2 = -1;
            }

            Back Slash
            if (i3 = 0 && j3 = 6 && s3 == 0)
            {
                if (State[i3][j3] == State[Row][Col]  State[i3][j3] == '.') win_2++;
                else s3 = -1;
                i3--, j3++;
            }
            if (i4 = 5 && j4 = 0 && s4 == 0)
            {
                if (State[i4][j4] == State[Row][Col]  State[i4][j4] == '.') win_2++;
                else s4 = -1;
                i4++, j4--;
            }
            if (win_2 = 3)
            {
                t_win_++;
                s3 = s4 = -1;
            }
        }

        return t_win_;
    }

    double EvaluateStateUtility(int PlayerID) {
        if (PlayerID == Winner)
            return 1;
        if (Winner = 0)
            return -1;

         In the remaining case the game is not over yet
         so write your code here to provide evaluation
        in all such cases here

         Study various evaluation functions and implement yours
         This functions will be needed by auto player
        double win_1 = 0, no_1 = 0;

        for (int i = 0; i  6; i++)
            for (int j = 0; j  7; j++)
                if (State[i][j] == PlayerSign[PlayerID])
                {
                    win_1 += Evaluate(i, j);
                    no_1++;
                }

        if (no_1 == 0) return 0;

        return (win_1)  (4  no_1);
    }

    void Show() {
        cout  endl;
        for (int r = 0; r  6; r++) {
            for (int c = 0; c  7; c++) {
                cout  State[r][c]  t;
            }
            cout  endl;
        }
        return;
    }

    bool MakeMove(int Move) {

        if (ValidateMove(Move)) {
            State[PossibleMoves[Move]][Move] = PlayerSign[MovingPlayer];
            CheckGameOver(Move);
            PossibleMoves[Move]--;
            MovingPlayer = (MovingPlayer + 1) % 2;
            Moves.push_back(Move);
            return true;
        }
        return false;
    }

    bool UndoLastMove() {
        if (Moves.size()  0) {
            int Col = Moves[Moves.size() - 1];
            PossibleMoves[Col]++;
            State[PossibleMoves[Col]][Col] = '.';
            MovingPlayer = (MovingPlayer + 1) % 2;
            if (Winner != -1)
                Winner = -1;
            Moves.pop_back();
            return true;
        }
        return false;
    }
};

class Player {   By Default it is a human player{;

public
    string PlayerName;
    char PlayerMark;  A single 8 bit char to code the color of a player
    unsigned int PlayerLevel;  Number of look ahead moves

    Player(string PlayerName,char PlayerMark, int Level = 0) {
        this-PlayerName = PlayerName;
        this-PlayerMark = PlayerMark;
        this-PlayerLevel = Level;
    }

    virtual int DecideMove(Connect4State& S) {

        bool Valid = false;
        int Move;
        do {
            cout  Please enter your move (1 - 7) ;

            cin  Move;
            Move--;
            Valid = S.ValidateMove(Move);

            if (!Valid)
                cout  Invalid Move   endl;
        } while (!Valid);

        return Move;
    };

};

class AutoC4Player  public Player {
private
    double pruning(Connect4State State,int MaxOrMin,double &Alpha,double &Beta,int PlayerLevel) 
    {
        if (PlayerLevel  2)
            return State.EvaluateStateUtility(0);

        vectorint Moves_used;
        for (int x = 0, i = 0; i  2 && i  State.validCol();)
        {
            x = 7  (int)rand()  RAND_MAX;
            if (count(Moves_used.begin(), Moves_used.end(), x) == 0)
            {
                Moves_used.push_back(x);
                i++;
            }
        }

        if (MaxOrMin) {
            double bestValue = Alpha;
            while (!Moves_used.empty())
            {
                State.MakeMove(Moves_used[Moves_used.size() - 1]); 
                bestValue = max(bestValue, pruning(State, ((MaxOrMin + 1) % 2), Alpha, Beta, PlayerLevel + 1));
                Alpha = max(Alpha, bestValue);
                State.UndoLastMove();
                Moves_used.pop_back();
                if (Beta = Alpha)
                    break;
            }
            return bestValue;
        }
        else {
            double bestValue = Beta;
            while (!Moves_used.empty())
            {
                State.MakeMove(Moves_used[Moves_used.size() - 1]);
                bestValue = min(bestValue, pruning(State, ((MaxOrMin + 1) % 2), Alpha, Beta, PlayerLevel + 1));
                Beta = min(Beta, bestValue);
                State.UndoLastMove();
                Moves_used.pop_back();
                if (Beta = Alpha)
                    break;
            }
            return bestValue;
        }
    }
    
    unsigned int minimax(Connect4State State,
        int MaxOrMin = 1,  Player making move
        int Alpha = INT_MIN,  -infinity
        int Beta = INT_MAX,  infinity
        unsigned int PlayerLevel = 1  depth of tree to make a decision
    ) {
         Your Code Goes Here
         The code must implement
         Minimax with pruning to decide a move here
         The auto player decides the move at random

        vectorint Moves_used;

        unsigned int x = 0;
        for (int i = 0; i  2 && i  State.validCol();)
        {
            x = 7  (float)rand()  RAND_MAX;
            if (count(Moves_used.begin(), Moves_used.end(), x) == 0)
            {
                Moves_used.push_back(x);
                i++;
            }
        }

        int best_choice = Moves_used[Moves_used.size() - 1];
        double A_ = INT_MIN, B_ = INT_MAX;

        State.MakeMove(Moves_used[Moves_used.size() - 1]);
        double bestValue = pruning(State, ((MaxOrMin + 1) % 2), A_, B_, PlayerLevel + 1), newvalue;

        State.UndoLastMove();
        Moves_used.pop_back();


        while (!Moves_used.empty())
        {
            State.MakeMove(Moves_used[Moves_used.size() - 1]);
            newvalue = pruning(State, ((MaxOrMin + 1) % 2), A_, B_, PlayerLevel + 1);
            if (bestValue != max(bestValue, newvalue))
            {
                bestValue = max(bestValue, newvalue);
                best_choice = Moves_used[Moves_used.size() - 1];
            }
            A_ = max(A_, bestValue);
            State.UndoLastMove();
            Moves_used.pop_back();
            if (B_ = A_)
                break;
        }

        return best_choice;
    }


public

    AutoC4Player(char Color = 'O') Player(AutoRandom, Color) {
    }

    int DecideMove(Connect4State& State) {
        return minimax(State, 1, INT_MIN, INT_MAX, this-PlayerLevel);
    }
};


class Connect4 {
private
    Player Players[2];
    Connect4State Board;

public

    Connect4(Player FirstPlayer, Player SecondPlayer, unsigned int MovingPlayer = 0) {
        this-Board.MovingPlayer = MovingPlayer;
        Board.PlayerSign[0] = FirstPlayer-PlayerMark;
        Board.PlayerSign[1] = SecondPlayer-PlayerMark;

        Players[0] = FirstPlayer;
        Players[1] = SecondPlayer;
    }

    int Play() {
        int Move;
        while (Board.Winner == -1) {
            Board.Show();
            cout  Players[Board.MovingPlayer]-PlayerName   Turning   endl;
            Move = Players[Board.MovingPlayer]-DecideMove(Board);
            if (Board.ValidateMove(Move))
                Board.MakeMove(Move);
            double v = Board.EvaluateStateUtility(0);
            double w = Board.EvaluateStateUtility(1);
        }
        return Board.Winner;
    }
};

int main() {
    Player Human(Human, 'X');
    AutoC4Player Auto('O');
    Connect4 Game(&Human, &Auto);
    int winner = Game.Play();
    if (winner == 3)
        cout  Game is a draw  endl;
    else if (winner == 1)
        cout  Player Won  endl;
    else
        cout  AutoPlayer Won  endl;
    return 0;
}