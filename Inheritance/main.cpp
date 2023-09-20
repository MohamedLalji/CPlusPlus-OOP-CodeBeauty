// Modification of code to reduce code repitition
// Improving the subscribers count method by allowing users to choose to unsubscribe/subscribe and based on that they will add/reduce count
// Making the Class attributes private
// Inheritance.. Derived class added

#include <iostream>
#include <list>
using namespace std;

// Creating a list with its attributes
class YoutubeChannel {
private:
	string name;
	int subscribersCount;
	list <string> publishedVideos;

//Adding the protected access modifier so properties in this can be accessed by the derived classes
protected:
	string ownerName;

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

	//Method that will allow subscribers count to be added when there is a new subscriber
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

//Creating a Derived class to show Inheritance.
class InspirationalYoutubeChannel:public YoutubeChannel{
public:
	//Constructor linked to the constructor of the base class
	InspirationalYoutubeChannel(string name, string ownerName) :YoutubeChannel(name, ownerName) {

	}

	//Creating a method that will only be accessible to the Derivved class and not the base class objects
	void Practice() {
		cout << ownerName <<" is practicing edits and trying different kinds of edits everyday to create better content for his followers." << endl << endl;	//OwnerName is accessible here beacuse it is in the protected access modifier nt private
	}
};

int main() {
	//Object created from the derivd class
	InspirationalYoutubeChannel editsChannel("ShiaSoulSpeaks", "Mohamed");

	//Calling the rest of the methods from base class and using them with the object created from the derived class
	editsChannel.publishedVideo("Glad Exposed");
	editsChannel.publishedVideo("Finding peace in the heart");
	editsChannel.publishedVideo("Respecting Muharram's solemnity");

	editsChannel.Subscribe();
	editsChannel.Subscribe();
	editsChannel.Unsubscribe();

	editsChannel.getInfo();

	editsChannel.Practice();

	 //New object created from the base class
	YoutubeChannel ytChannel1("How to kill", "Saddam Hussein");

	ytChannel1.Subscribe();	
	ytChannel1.Subscribe();

	ytChannel1.publishedVideo("How I killed millions of people mercilessly");

	ytChannel1.getInfo();

	return 0;
}