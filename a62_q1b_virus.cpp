#include <bits/stdc++.h>
using namespace std;

bool DOVICchecker(string gene, bool front, int bits, bool full_bits)
{

  //if (full_bits)
  //{
    if (bits == 4)
    {
      if (gene != "0101" && gene != "1001")
      {
        return false;
      }

      return true;
    }
    else if (bits == 2)
    {
      if (gene != "01") return false;

      return true;
    }
  /*}
  else
  {
    if (bits == 4)
    {
      if (gene != "0101" && gene != "1010" && gene != "1001")
      {
        return false;
      }

      return true;
    }
    else if (bits == 2)
    {
      if (gene != "01" && gene != "10") return false;

      return true;
    }
  }*/

  string frontGene = gene.substr(0, bits / 2);
  string frontGeneReverse = frontGene;
  reverse(frontGeneReverse.begin(), frontGeneReverse.end());
  string backGene = gene.substr(bits / 2);

  
  bool left1 = DOVICchecker(frontGene, true, bits / 2, false);
  bool left2 = DOVICchecker(frontGeneReverse, true, bits / 2, false);
  bool right = DOVICchecker(backGene, false, bits / 2, false);

  return (left1 || left2) && right;
}

int main()
{
  int n_Check{}, k_2PowerK{};
  cin >> n_Check >> k_2PowerK;
  int bits_length = pow(2, k_2PowerK);
  for (int i = 0; i < n_Check; i++)
  {
    string gene;
    for (int i = 0; i < bits_length; i++)
    {
      string bit{};
      cin >> bit;
      gene.append(bit);
    }
    if (DOVICchecker(gene, true, bits_length, true))
    {
      cout << "yes" << "\n";
    }
    else
    {
      cout << "no" << "\n";
    }
  }
}