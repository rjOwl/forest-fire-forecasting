#include <iostream>
#include "NetworkClient.h"

using namespace std;

int main()
{
    NetworkClient con = NetworkClient();
    cout << "Hello world!" << endl;
    string i = "WOW";
    cout << con.get_temp()<< endl;
    return 0;
}
