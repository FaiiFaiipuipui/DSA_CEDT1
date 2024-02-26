#include <bits/stdc++.h>
using namespace std;

void printer (int (&arr)[], int& n)
{
  /*for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl << endl;*/
}

void printer2 (int i, int j)
{
  //cout << i << " " << j << endl;
}

int main()
{
  int nInput{}, sum1{}, sum2{}, sum3{}, changeSum{};
  cin >> nInput;
  int arr[nInput];
  for (int i = 0; i < nInput; i++)
  {
    int inputTemp{};
    cin >> inputTemp;
    arr[i] = inputTemp;
    if (inputTemp == 1) sum1++;
    else if (inputTemp == 2) sum2++;
    else if (inputTemp == 3) sum3++;
  }

  int oneS = 0;
  int twoS = sum1;
  int threeS = sum1 + sum2;
  bool sorted{}, more1{true}, more2{true}, more3{true};

  while (more1)
  {
    bool reallyMore{};
    for (int j = oneS; j < twoS; j++)
    {
      for (int i = twoS; i < nInput; i++)
      {
        if (arr[i] == 1 && arr[j] == 2 && i < threeS)
        {
          swap(arr[i], arr[j]);
          changeSum++;
          printer(arr, nInput);
          printer2(arr[i], arr[j]);
          reallyMore = true;
        }
        else if (arr[i] == 1 && arr[j] == 3 && i >= threeS)
        {
          swap(arr[i], arr[j]);
          changeSum++;
          printer(arr, nInput);
          printer2(arr[i], arr[j]);
          reallyMore = true;
        }
      }
    }

    if (!reallyMore) more1 = false;
  }

  while (more2)
  {
    bool reallyMore{};
    for (int j = twoS; j < threeS; j++)
    {
      for (int i = threeS; i < nInput; i++)
      {
        if (arr[i] == 2 && arr[j] == 3 && i >= threeS)
        {
          swap(arr[i], arr[j]);
          changeSum++;
          printer(arr, nInput);
          printer2(arr[i], arr[j]);
          reallyMore = true;
        }
      }

      for (int i = oneS; i < twoS; i++)
      {
        if (arr[i] == 2 && arr[j] == 1 && i >= oneS)
        {
          swap(arr[i], arr[j]);
          changeSum++;
          printer(arr, nInput);
          printer2(arr[i], arr[j]);
          reallyMore = true;
        }
      }
    }

    if (!reallyMore) more2 = false;
  }

  while (more3)
  {
    bool reallyMore{};
    for (int j = threeS; j < nInput; j++)
    {
      for (int i = oneS; i < threeS; i++)
      {
        if (arr[i] == 3 && arr[j] == 1 && i < twoS)
        {
          swap(arr[i], arr[j]);
          changeSum++;
          printer(arr, nInput);
          printer2(arr[i], arr[j]);
          reallyMore = true;
        }

        if (arr[i] == 3 && arr[j] == 2 && i < threeS)
        {
          swap(arr[i], arr[j]);
          changeSum++;
          printer(arr, nInput);
          printer2(arr[i], arr[j]);
          reallyMore = true;
        }

      }
    }

    if (!reallyMore) more3 = false;
  }

  //cout << "SLOW SORT" << endl;

  while (!sorted)
  {
    bool isSorted{true};
    for (int i = 0; i < nInput - 1; i++)
    {
      if (arr[i + 1] < arr[i]) isSorted = false;
    }
    if (isSorted)
    {
      sorted = true;
      break;
    }

    for (int i = 0; i < nInput; i++)
    {
      for (int j = i + 1; j < nInput; j++)
      {
        if (i >= threeS)
        {
          if (arr[j] == 3 && arr[i] != 3 && j < threeS)
          {
            swap(arr[i], arr[j]);
            changeSum++;
            printer(arr, nInput);
            printer2(arr[i], arr[j]);
          }
        }
        else if (i >= twoS && (j >= oneS && j < twoS || j >= threeS))
        {
          if (arr[j] == 2 && arr[i] != 2)
          {
            swap(arr[i], arr[j]);
            changeSum++;
            printer(arr, nInput);
            printer2(arr[i], arr[j]);
          }
        }
        else
        {
          if (arr[j] == 1 && arr[i] != 1)
          {
            swap(arr[i], arr[j]);
            changeSum++;
            printer(arr, nInput);
            printer2(arr[i], arr[j]);
          }
        }
      }
    }
  }

  cout << changeSum;
}   