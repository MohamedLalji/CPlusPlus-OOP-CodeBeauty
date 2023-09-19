#include <iostream>
#include <list>
using namespace std;


// Creating a list with its attributes
class YoutubeChannel {
public:								// Makes the attributes of a class public... private by default
	string name;
	string ownerName;
	int subscribersCount;
	list <string> publishedVideos;
};

int main() {

	//Creating an object
	YoutubeChannel ytchannel;

	//Accessing and assigning the properties
	ytchannel.name = "ShiaSoulSpeaks";
	ytchannel.ownerName = "Mohamed Lalji";
	ytchannel.subscribersCount = 125;
	ytchannel.publishedVideos = { "Glad Exposed", "Finding peace in the Heart", "Respecting Muharrams solemnity" };

	//Printing to the console
	cout << "Name: " << ytchannel.name << endl;
	cout << "Owner name: " << ytchannel.ownerName << endl;
	cout << "Subscribers Count: " << ytchannel.subscribersCount << endl;
	cout << "Published Videos: " << endl;
	for (string videosPublished: ytchannel.publishedVideos)
	{
		cout << videosPublished << endl;
	}

	 

	system("pause>0");
}