#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <list>

using namespace std;


/* (1.1) Is Unique: Implement an algorithm to determine if a string has all unique characters. 
What if you cannot use additional data structures? */
int isUnique(char* s)
{
	int checker = 0, step = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		step = s[i] - 'a';

		if ((checker & (1 << step)) > 0) 
		{
			return 0;
		}
		else
		{
			checker |= (1 << step);
		}
	}
	return 1;
}
//----------------------------------------------------------------------------------------------------


/* (1.2) Check Permutation: Given two strings, write a method to decide if one is a permutation of the other. */
bool checkPermutation(const string &s1, const string &s2)
{
    int sum1 = 0, sum2 = 0;

	if (s1.length() != s2.length())
	{
		return false;
	}

	for (int i = 0; i < s1.length(); i++)
	{
		sum1 += s1[i];	// In C++, char values are automatically promoted to int when used in expressions where an integer is expected.
		sum2 += s2[i];
	}

	return (sum1 == sum2) ? true : false;
}
//----------------------------------------------------------------------------------------------------



/* (1.3) URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string. For example:
Input: "Mr John Smith    ", 13
Output: "Mr%20John%20Smith" 	*/
char* replaceSpaces(char *str, int length)
{
    int cnt = 0;

	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ') cnt++;
	}

	if (cnt == 0) return str;
	
	int i = length - 1;

	while (cnt > 0)
	{
		if (str[i] != ' ')
		{
			str[i + 2*cnt] = str[i];
		}
		else
		{
			cnt--;
			str[i + 2*cnt] = '%';
			str[(i+1) + 2*cnt] = '2';
			str[(i+2) + 2*cnt] = '0';
		}
		i--;
	}

	return str;
}
//----------------------------------------------------------------------------------------------------



/* (1.4) Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
EXAMPLE:
Input: 'Tact Coa'
Output: True (permutations: "taco cat", "atco eta", etc.) */
bool permutationPalindrome(const string& s)
{
    int checker = 0, shift = 0;
	
	for (int i = 0; s[i] != '\0'; i++)
	{
		shift = s[i] - 'a';
		
		if ((checker & (1 << shift)) == 0)	// bit i is '0'
		{
			checker |= 1 << shift;	// toggle '0'
		}
		else
		{
			checker &= ~(1 << shift);	// toggle '1'
		}
	}
	
	if (checker == 0) return true;

	int temp = checker - 1;

	if ((checker & temp) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//----------------------------------------------------------------------------------------------------



/* (1.5) One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character.
Given two strings, write a function to check if they are one edit (or zero edits) away.
EXAMPLE:
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false  */
int checkOneAway(const char *s1, const char *s2)
{
    int difference_flag = 0, n1 = strlen(s1), n2 = strlen(s2);

	if (abs(n1 - n2) > 1) return 0;

	const char* smaller_s = (n1 < n2) ? s1:s2;
	const char* larger_s = (n1 < n2) ? s2:s1;

	int i = 0, j = 0;

	while ((smaller_s[i] != '\0') && (larger_s[j] != '\0'))
	{
		if (smaller_s[i] != larger_s[j])
		{
			if (difference_flag) return 0;

			difference_flag = 1;

			if (n1 == n2)
			{
				i++;	// On Replace, increament the smaller_s index too.
			}
		}
		else
		{
			i++;	// On Replace, increament the smaller_s index too.
		}
		j++; // Always increament the larger_s index.
	}
	
	return 1;
}
//----------------------------------------------------------------------------------------------------



/* (1.6) String Compression: Implement a method to perform basic string compression using the counts of repeated characters.
For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string,
your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).  */
string compression(string& s)
{
	if (s[0] == '\0') return s;

	list<char> compressed_list;

	int ref_idx = 0, curr_idx = 1;

	for (; s[curr_idx] != '\0'; curr_idx++)
	{
		if (s[ref_idx] != s[curr_idx])	// There is sequence of repeated characters
		{
			compressed_list.push_back(s[ref_idx]);		// Copy the reference char to the list
			compressed_list.push_back((curr_idx - ref_idx) + '0');	// write the number of repetitions of the char

			ref_idx = curr_idx;		// If s[ref_idx] != s[curr_idx], update ref_idx
		}
	}

	// Add the last character of s and its number of repetitions:
	compressed_list.push_back(s[ref_idx]);
	compressed_list.push_back((curr_idx - ref_idx) + '0');

	string compressed_str(compressed_list.begin(), compressed_list.end());	// Use constructor to convert list object to string object

	return (s.length() > compressed_str.length()) ? compressed_str : s; // return the shorter string
}
//----------------------------------------------------------------------------------------------------



/* (1.7) Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place? */
void rotate(int **img, int N)
{
    int temp_top;

	for (int row = 0; row < N/2; row++)
	{
		for (int col = row; col < N - 1 - row; col++)
		{
			temp_top = img[row][col];	// copy the top value

			img[row][col] = img[N - 1 - col][row];	// move left to top 

			img[N - 1 - col][row] = img[N - 1 - row][N - 1 - col];	// move bottom to left 

			img[N - 1 - row][N - 1 - col] = img[col][N - 1 - row];	// move right to bottom 

			img[col][N - 1 - row] = temp_top;	// move top to right
		}
	}	
}
//----------------------------------------------------------------------------------------------------



/* (1.8) Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0. */
void zeroMat(int **mat, int M, int N)
{
	bool rowHasZero = false; // Indicates if a specific row has a zero.
	bool wasZero = false; // Indicates if there is at least one zero in the entire matrix.

	// Search zeros:
	for (int row = 0; row < M; row++)
	{
		for (int col = 0; col < N; col++)
		{
			if (mat[row][col] == 0)
			{
				rowHasZero = true;
				wasZero = true;
				mat[0][col] = 0;	// Set the appropriate column in the first row to be zero.
			}
		}
		if (rowHasZero)
		{
			for (int column = 0; column < N; column++)
			{
				mat[row][column] = 0; // Reset a specific row.
			}
			rowHasZero = false;
		}
	}
	if (!wasZero) return;

	int row = 1;

	for (int col = 0; col < N; col++)	// Reset columns
	{
		if (mat[0][col] == 0)
		{
			for (row = 1; row < M; row++)
			{
				mat[row][col] = 0; 	// Reset the entire column.
			}
		}
	}
}
//----------------------------------------------------------------------------------------------------



/* (1.9) String Rotation: Assume you have a method isSubstring which checks if one word is a substring
of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one
call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").  */

bool isSubstring(string s1, string s2)	// This function written only for checking the code of isRotation(). In problem 1.9 we assume that we have the function isSubstring()
{
	if (s1.find(s2) != string::npos) 
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------------------------------


bool isRotation(string s1, string s2)
{

	if (s1.length() != s2.length()) return false;
	
	int rotPoint = -1;		// rotPoint = - 1 means that rotation point not found

	int i = 0, j = s2.length() - 1; 

	for (; j >= 0; j--)		// Search the rotation point
	{
		if (s1[i] == s2[j])
		{
			rotPoint = j;
			break;
		}
	}
	
	if (rotPoint == -1) return false;

	j = rotPoint;

	for (; s2[j] != '\0'; j++)	// Check that the right part of s2 is the left part of s1
	{
		if (s1[i] != s2[j])
		{
			return false;
		}
		i++;
	}

	if (isSubstring(s1, s2.substr(0, rotPoint)))	// substr(int start_idx, int length) is a member of class <string>
	{
		return true;
	}

	return false;
}


