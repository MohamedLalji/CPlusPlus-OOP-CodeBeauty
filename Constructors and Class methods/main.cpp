//Modification of code to reduce code repitition
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

	//Constructor that takes 2 parameters and assigns values to them
	YoutubeChannel(string cname, string ownername) {
		name = cname;
		ownerName = ownername;
		subscribersCount = 0;
	}

	//Implementing class method that will allow the output to be printed without code repition
	void getInfo() {
		cout << "Name: " << name << endl;
		cout << "Owner name: " << ownerName << endl;
		cout << "Subscribers Count: " << subscribersCount << endl;
		cout << "Published Videos: " << endl;
		for (string videosPublished : publishedVideos)
		{
			cout << videosPublished << endl;
		}
	}
};

int main() {

	//Creating an object and assigning it values based on values assigned by the constructor
	YoutubeChannel ytchannel("ShiaSoulSpeaks", "Mohamed Lalji");
	ytchannel.publishedVideos.push_back("Glad Exposed");					//Push_back can be used to add lines to previous vector... In this case it will assign  "" to publishedVideos 
	ytchannel.publishedVideos.push_back("Finding peace in the Heart");
	ytchannel.publishedVideos.push_back("Respecting Muharrams solemnity");

	YoutubeChannel ytchannel2("Shia Wisdom", "Rahul Patel");


	//Printing to the console using class method getInfo
	ytchannel.getInfo();
	ytchannel2.getInfo();


	return 0;
}