#include <iostream>
#include <algorithm>

using namespace std;

void ordem(float &num1, float &num2, float &num3, float &num4)
{
  float num_ordem[4] = {num1, num2, num3, num4};
  sort(num_ordem, num_ordem + 4);
  num1 = num_ordem[0];
  num2 = num_ordem[1];
  num3 = num_ordem[2];
  num4 = num_ordem[3];

}

int main()
{
  float num1, num2, num3, num4;

  cout << "Informe quatro números float: " << endl;
  cin >> num1 >> num2 >> num3 >> num4;

  ordem(num1,num2,num3,num4);

  cout << "Os números em ordem: " << num1 << " " << num2 << " " << num3 << " " << num4 << endl;
  
  return 0;
}