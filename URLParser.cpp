#include<iostream>
#include<cstring>

int main()
{
	std::string url, scheme, authority, path;
	int colon, slash, doubleSlash, authorityChar;

	std::cout << "Please enter a URL: ";
	std::cin >> url;
	colon = url.find(":");

	for (int i = 0; i < url.size(); i++) {
		if (url[i] == '/' && url[i + 1] == '/') {
			doubleSlash = i;
			i++;
		}
		else if (url[i] == '/' && url[i + 1] != '/') {
			slash = i;
			break;
		}
	}

	scheme = url.substr(0, colon + 1);
	authorityChar = ((url.size() - colon) - (url.size() - slash)) - 1;
	authority = url.substr(doubleSlash, authorityChar);
	path = url.substr(slash);

	std::cout << "Scheme = " << scheme << "\n"; 
	std::cout << "Authority = " << authority << "\n";
	std::cout << "Path = " << path << "\n"; 
}