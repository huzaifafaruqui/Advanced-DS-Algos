
int Manhattan(const char& a, const char& b)
{
	return abs(b - a - 2*'a');
}


int Manhattan(const int& source, const int& destination)
{
	return abs(destination - source);
}


int Manhattan(const std::pair<int, int>& source, const std::pair<int,int>& destination)
{
	return abs(destination.first - source.first) + abs(destination.second - source.second);
}
