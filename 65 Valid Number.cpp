class Solution {
public:
    class State{
    public:
        virtual State & next(char) = 0;
        virtual bool value() = 0;
    };
    
    class StateFactory{
    public:
        virtual State & getInit() = 0;
        virtual State & getLeadingDot() = 0;
        virtual State & getLeadingSign() = 0;
        virtual State & getNumberBeforeDotAndE() = 0;
        virtual State & getDotBeforeE() = 0;
        virtual State & getNumberAfterDotBeforeE() = 0;
        virtual State & getE() = 0;
        virtual State & getSignAfterE() = 0;
        virtual State & getNumberAfterEBeforeDot() = 0;
        virtual State & getSufixSpace() = 0;
        virtual State & getInvalid() = 0;
    };
    
    class Init : public State{
    public:
        Init(StateFactory & factory):factory(factory){};
        State & next(char c){
            if(c == ' ') return *this;
            if(c == '.') return factory.getLeadingDot();
            if(c <= '9' && c >= '0') return factory.getNumberBeforeDotAndE();
            if(c == '+' || c == '-') return factory.getLeadingSign();
            return factory.getInvalid();
        }
        bool value(){
              cout << '1';
            return false;}
    private:
        StateFactory & factory;
    };

    
    class LeadingDot : public State{
    public:
        LeadingDot(StateFactory & factory):factory(factory){};
        State & next(char c){
            if(c <= '9' && c >= '0') return factory.getNumberAfterDotBeforeE();
            return factory.getInvalid();
        }
        bool value(){return false;}
    private:
        StateFactory & factory;
    };
    
    class LeadingSign : public State{
    public:
        LeadingSign(StateFactory & factory):factory(factory){};
        State & next(char c){
            if(c <= '9' && c >= '0') return factory.getNumberBeforeDotAndE();
            if(c == '.') return factory.getLeadingDot();
            return factory.getInvalid();
        }
        bool value(){
            return false;}
    private:
        StateFactory & factory;
    };
    
    class NumberBeforeDotAndE : public State{
    public:
        NumberBeforeDotAndE(StateFactory & factory):factory(factory){};
        State & next(char c){
            if(c <= '9' && c >= '0') return factory.getNumberBeforeDotAndE();
            if(c == '.') return factory.getDotBeforeE();
            if(c == 'e') return factory.getE();
            if(c == ' ') return factory.getSufixSpace();
            return factory.getInvalid();
        }
        bool value(){
            cout << 3;
            return true;}
    private:
        StateFactory & factory;
    };
    
    class DotBeforeE : public State{
    public:
        DotBeforeE(StateFactory & factory):factory(factory){};
        State & next(char c){
            if(c <= '9' && c >= '0') return factory.getNumberAfterDotBeforeE();
            if(c == ' ') return factory.getSufixSpace();
            if(c == 'e') return factory.getE();
            return factory.getInvalid();
        }
        bool value(){return true;}
    private:
        StateFactory & factory;
    };
    
    class NumberAfterDotBeforeE : public State{
    public:
        NumberAfterDotBeforeE(StateFactory & factory):factory(factory){};
        State & next(char c){
            if(c <= '9' && c >= '0') return factory.getNumberAfterDotBeforeE();
            if(c == 'e') return factory.getE();
            if(c == ' ') return factory.getSufixSpace();
            return factory.getInvalid();
        }
        bool value(){return true;}
    private:
        StateFactory & factory;
    };
    
    class E : public State{
    public:
        E(StateFactory & factory):factory(factory){};
        State & next(char c){
            if(c <= '9' && c >= '0') return factory.getNumberAfterEBeforeDot();
            if(c == '+' || c == '-') return factory.getSignAfterE();
            return factory.getInvalid();
        }
        bool value(){return false;}
    private:
        StateFactory & factory;
    };
    
    class SignAfterE : public State{
    public:
        SignAfterE(StateFactory & factory):factory(factory){};
        State & next(char c){
            if(c <= '9' && c >= '0') return factory.getNumberAfterEBeforeDot();
            return factory.getInvalid();
        }
        bool value(){return false;}
    private:
        StateFactory & factory;
    };
    
    class NumberAfterEBeforeDot : public State{
    public:
        NumberAfterEBeforeDot(StateFactory & factory):factory(factory){};
        State & next(char c){
            if(c <= '9' && c >= '0') return factory.getNumberAfterEBeforeDot();
            if(c == ' ') return factory.getSufixSpace();
            return factory.getInvalid();
        }
        bool value(){return true;}
    private:
        StateFactory & factory;
    };

    class SufixSpace : public State{
    public:
        SufixSpace(StateFactory & factory):factory(factory){};
        State & next(char c){
            if(c == ' ') return factory.getSufixSpace();
            return factory.getInvalid();
        }
        bool value(){return true;}
    private:
        StateFactory & factory;
    };

    class Invalid : public State{
    public:
        Invalid(StateFactory & factory):factory(factory){};
        State & next(char c){
            return factory.getInvalid();
        }
        bool value(){return false;}
    private:
        StateFactory & factory;
    };

    
    class NumberJudgerFactory : public StateFactory{
    public:
        State & getInit() {
            cout << 0;
            return init;
        };
        State & getLeadingDot() {
            cout << 1;
            return leadingDot;
        };
        State & getLeadingSign() {
            cout << 2;
            return leadingSign;
        };
        State & getNumberBeforeDotAndE() {
            cout << 3;
            return numberBeforeDotAndE;
        };
        State & getDotBeforeE() {
            cout << 4;
            return dotBeforeE;
        };
        State & getNumberAfterDotBeforeE() {
            cout << 5;
            return numberAfterDotBeforeE;
        };
        State & getE() {
            cout << 6;
            return e;
        };
        State & getSignAfterE() {
            cout << 7;
            return signAfterE;
        };
        State & getNumberAfterEBeforeDot() {
            cout << 8;
            return numberAfterEBeforeDot;
        };
        State & getSufixSpace() {
            cout << -2;
            return sufixSpace;
        };
        State & getInvalid() {
            cout << -3;
            return invalid;
        };
    private:
        Init init{*this};
        LeadingDot leadingDot{*this};
        LeadingSign leadingSign{*this};
        NumberBeforeDotAndE numberBeforeDotAndE{*this};
        DotBeforeE dotBeforeE{*this};
        NumberAfterDotBeforeE numberAfterDotBeforeE{*this};
        E e{*this};
        SignAfterE signAfterE{*this};
        NumberAfterEBeforeDot numberAfterEBeforeDot{*this};
        SufixSpace sufixSpace{*this};
        Invalid invalid{*this};
    };
    
    bool isNumber(string s) {
        NumberJudgerFactory factory;
        State * state = &(factory.getInit());
        for(int i = 0; i < s.length(); i++){
            state = &(state->next(s[i]));
        }
        return state->value();
    }
};