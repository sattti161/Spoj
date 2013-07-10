#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool const debug_flag = true;

bool CheckIfPalin(vector<int> digits);
int NextPalin(int num);
vector<int> NumtoDigit(int number);


int main(int argc, char *argv[]){
  int t, num;
  cin >> t;
  vector <int> next_palins;
  for (int i = 0; i < t; i++) {
    cin >> num;
    next_palins.push_back(NextPalin(num));
  }
  
  for (int i = 0; i < next_palins.size(); i++) 
    cout << next_palins[i] << endl;

}


int NextPalin(int num){
    int i = num + 1;
    bool flag = false;
    while(!flag){
	vector<int> digits = NumtoDigit(i);
	if(CheckIfPalin(digits))
	    return i;
	i++;
    }
}


bool CheckIfPalin(vector<int> digits){
    for(int i = 0; i < digits.size(); i++){
	if(digits[i] != digits[digits.size() - 1 - i])
	    return false;
    }
    return true;

}


vector<int> NumtoDigit(int number){
    vector<int> digit_vector;
    
    while(number > 0){
	digit_vector.insert(digit_vector.end(), number % 10);
	number = number / 10;
    }
    return digit_vector;   
}
