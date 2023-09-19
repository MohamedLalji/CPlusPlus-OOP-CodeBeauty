// Modification of code to reduce code repitition
// Improving the subscribers count method by allowing users to choose to unsubscribe/subscribe and based on that they will add/reduce count
// Making the Class attributes private
#include <iostream>
#include <list>
using namespace std;


// Creating a list with its attributes
class YoutubeChannel {
private:								
	string name;
	string ownerName;
	int subscribersCount;
	list <string> publishedVideos;

public:
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

	//Mrthod that will allow subscribers count to be added when there is a new subscriber
	void Subscribe()
	{
		subscribersCount++;
	}

	void Unsubscribe() {
		if (subscribersCount > 0)
			subscribersCount--;
	}

	// Accesses the private attribute publishedVideos
	void publishedVideo(string title) {
		publishedVideos.push_back(title);				//Push_back can be used to add lines to previous vector... In this case it will assign  "" to publishedVideos 
	}
};

int main() {

	//Creating an object and assigning it values based on values assigned by the constructor
	YoutubeChannel ytchannel("ShiaSoulSpeaks", "Mohamed Lalji");
	ytchannel.publishedVideo("Glad Exposed");					
	ytchannel.publishedVideo("Finding peace in the Heart");
	ytchannel.publishedVideo("Respecting Muharrams solemnity");
	ytchannel.Subscribe();
	ytchannel.Subscribe();
	ytchannel.Subscribe();
	ytchannel.Unsubscribe();

	//Second Object
	YoutubeChannel ytchannel2("Shia Wisdom", "Rahul Patel");
	ytchannel2.publishedVideo("Ammar Nakshawani on mental health");
	ytchannel2.Subscribe();

	//Printing to the console using class method getInfo
	ytchannel.getInfo();
	ytchannel2.getInfo();


	return 0;
}