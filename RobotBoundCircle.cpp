#include <string>
using namespace std;
class State {
private :
    int m_X;
    int m_Y;
    int m_Direction;
public:
    State(int mX, int mY, int mDirection) : m_X(mX), m_Y(mY), m_Direction(mDirection) {

    }

    int getMX() const {
        return m_X;
    }

    int getMY() const {
        return m_Y;
    }

    int getMDirection() const {
        return m_Direction;
    }

};
class Solution {

public:
    State getNext(const State & state,char command) {

        switch (command) {
            case 'G' : {
                switch (state.getMDirection()) {
                    case 0 : {
                        return State(state.getMX(),state.getMY()+1,state.getMDirection());
                    }
                    case 1 : {
                        return State(state.getMX()-1,state.getMY(),state.getMDirection());
                    }
                    case 2 : {
                        return State(state.getMX(),state.getMY()-1,state.getMDirection());
                    }
                    case 3 : {
                        return State(state.getMX()+1,state.getMY(),state.getMDirection());
                    }
                }
            }
            case 'L' : {
                switch (state.getMDirection()) {
                    case 0 : {
                        return State(state.getMX(),state.getMY(),1);
                    }
                    case 1 : {
                        return State(state.getMX(),state.getMY(),2);
                    }
                    case 2 : {
                        return State(state.getMX(),state.getMY(),3);
                    }
                    case 3 : {
                        return State(state.getMX(),state.getMY(),0);
                    }
                }
            }
            case 'R' : {
                switch (state.getMDirection()) {
                    case 0 : {
                        return State(state.getMX(),state.getMY(),3);
                    }
                    case 1 : {
                        return State(state.getMX(),state.getMY(),0);
                    }
                    case 2 : {
                        return State(state.getMX(),state.getMY(),1);
                    }
                    case 3 : {
                        return State(state.getMX(),state.getMY(),2);
                    }
                }
            }
        }

        return State(0,0,0);
    }
    bool isRobotBounded(string instructions) {
        auto s = State(0,0,0);
        for (auto ch : instructions) {
            s = getNext(s,ch);
        }

        if ((s.getMX() == 0 && s.getMY() == 0) || s.getMDirection() != 0) {
            return true;
        }else {
            return false;
        }
    }
};

int main() {

}
