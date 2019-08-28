#define MAX_DIGIT 1 
#define BASE 10 
struct BigInt{
    vector <int> Digit;
    BigInt() {
        Digit.push_back(0);
    }
};