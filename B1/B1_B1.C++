#include <bits/stdc++.h>
using namespace std;

#include <string>

bool check_phone_number(const std::string &phone_number)
{
	if (phone_number.length() != 10)
	{
		return false; // Phone number length is not 10, so return false
	}
	for (char digit : phone_number)
	{
		if (digit < '0' || digit > '9')
		{
			return false; // Phone number contains non-digit characters
		}
	}
	return true; // Phone number length is 10 and contains only digits, so return true
}

int calculate_time_call(const string from_time, const string to_time)
{

	int start_time = ((from_time[0] - '0') * 10 + (from_time[1] - '0')) * 3600 + ((from_time[3] - '0') * 10 + (from_time[4] - '0')) * 60 + (from_time[6] - '0') * 10 + (from_time[7] - '0');
	int end_time = ((to_time[0] - '0') * 10 + (to_time[1] - '0')) * 3600 + ((to_time[3] - '0') * 10 + (to_time[4] - '0')) * 60 + (to_time[6] - '0') * 10 + (to_time[7] - '0');
	return end_time - start_time;
}
int main()
{
	unordered_map<string, int> number_calls_from;
	int number_total_calls = 0;
	int valid_phone_number = 1;
	unordered_map<string, int> count_time_calls_from;

	while (true)
	{
		string CALL, from_number, to_number, date, from_time, end_time;
		int time_call;
		cin >> CALL;
		if (CALL == "#")
			break;
		else
		{
			cin >> from_number >> to_number >> date >> from_time >> end_time;
			if (!check_phone_number(from_number) || !check_phone_number(to_number))
				valid_phone_number = 0;
			number_calls_from[from_number]++;
			number_total_calls++;
			time_call = calculate_time_call(from_time, end_time);
			count_time_calls_from[from_number] += time_call;
		}
	}

	while (true)
	{
		string query;
		cin >> query;
		if (query == "#")
			break;

		if (query == "?check_phone_number")
		{
			cout << valid_phone_number << endl;
		}
		else if (query == "?number_calls_from")
		{
			string from_number;
			cin >> from_number;
			cout << number_calls_from[from_number] << endl;
		}

		else if (query == "?number_total_calls")
		{
			cout << number_total_calls << endl;
		}
		else if (query == "?count_time_calls_from")
		{
			string from_number;
			cin >> from_number;
			cout << count_time_calls_from[from_number] << endl;
		}
	}
}