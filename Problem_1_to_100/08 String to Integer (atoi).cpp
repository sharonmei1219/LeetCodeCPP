
class Solution {
public:
    class stateFactory;

	class opState{
	public:
		virtual opState * next(char input, stateFactory & factory) = 0;
		virtual int op(long origin, char input) = 0;
	};

	class stateFactory{
	public:
		virtual opState * getInitState() = 0;
		virtual opState * getMinusState() = 0;
		virtual opState * getNumState() = 0;
		virtual opState * getTerminateState() = 0;
	};


	class initState : public opState{
	public:
		opState * next(char input, stateFactory & factory) {
			if (input == ' '){
				return this;
			}
			if (input == '-'){
				return factory.getMinusState();
			}
            if (input == '+'){
				return factory.getNumState();
			}
			if (input < '0' || input > '9'){
				return factory.getTerminateState();
			}
			return  factory.getNumState();
		}

		int op(long origin, char input) {
			if(input >='0' && input<='9'){
				return input - '0';
			}
			return 0;
		}
	};

	class minusOp : public opState{
		opState * next(char input, stateFactory & factory) {
			if (input < '0' || input > '9'){
				return factory.getTerminateState();
			}
			return this;
		}

		int op(long origin, char input) {
			if(input >='0' && input<='9'){
				long res = origin * 10 - (input - '0');
				if(res < INT_MIN) return INT_MIN;
				return res;
			}
			return origin;
		}
	};

	class numOp : public opState{
		opState * next(char input, stateFactory & factory) {
			if (input < '0' || input > '9'){
				return factory.getTerminateState();
			}
			return this;
		}

		int op(long origin, char input) {
			if(input >='0' && input<='9'){
				long res = origin * 10 + input - '0';
				if(res > INT_MAX) return INT_MAX;
				return res;
			}
			return origin;
		}
	};

	class terminateOp : public opState{
		opState * next(char input, stateFactory & factory) {
			return this;
		}

		int op(long origin, char input) {
			return origin;
		}
	};

    class concreteFactory : public stateFactory{
    public:
    	opState * getInitState() {return & init;}
    	opState * getMinusState() {return & minus;}
    	opState * getNumState() {return & num;}
    	opState * getTerminateState() {return & terminate;}
    private:
    	initState init;
    	minusOp minus;
    	numOp num;
    	terminateOp terminate;
    };

    int myAtoi(string str) {
		concreteFactory factory;
		opState * state = factory.getInitState();
		int result = 0;
    	for(int i = 0; i < str.length(); i++){
    		result = state->op(result, str[i]);
    		state = state->next(str[i], factory);
    	}
        return result;
    }
};