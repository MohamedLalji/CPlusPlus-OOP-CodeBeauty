// Modification of code to reduce code repitition
// Improving the subscribers count method by allowing users to choose to unsubscribe/subscribe and based on that they will add/reduce count
// Making the Class attributes private
// Inheritance.. Derived class added
// Polymorphism.. 

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
	int contentQuality;
public:
	//Constructor that takes 2 parameters and assigns values to them
	YoutubeChannel(string cname, string ownername) {
		name = cname;
		ownerName = ownername;
		subscribersCount = 0;
		contentQuality = 0;
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
		cout << endl;
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

	//This is declared in the base class since it will be used for all youtube channels and not just this one specifically
	void VideoAnalytics() {
		if (contentQuality < 5)
		{
			cout << name << " has bad quality content" << endl;
		}
		else
		{
			cout << name << " has great content" << endl;
		}
	}
};

//Creating a Derived class to show Inheritance.
class InspirationalYoutubeChannel :public YoutubeChannel {
public:
	//Constructor linked to the constructor of the base class
	InspirationalYoutubeChannel(string name, string ownerName) :YoutubeChannel(name, ownerName) {

	}
	//Creating a method that will only be accessible to the Derivved class and not the base class objects
	void Practice() {
		cout << ownerName << " is practicing edits and trying different kinds of edits everyday to create better content for his followers." << endl << endl;	//OwnerName is accessible here beacuse it is in the protected access modifier nt private
		contentQuality++;
	}
};

//Creating a Derived class to show Inheritance.
class GamingChannel :public YoutubeChannel {
public:
	//Constructor linked to the constructor of the base class
	GamingChannel(string name, string ownerName) :YoutubeChannel(name, ownerName) {

	}
	//Creating a method that will only be accessible to the Derivved class and not the base class objects
	void Practice() {
		cout << ownerName << " is practicing long hours, trying out different games, and spending alot of money on ingame purchases." << endl << endl;	//OwnerName is accessible here beacuse it is in the protected access modifier nt private
		contentQuality++;
	}
};

int main() {
	InspirationalYoutubeChannel ytChannel1("Soviet Union", "Joseph Stalin");
	GamingChannel ytChannel2("The Nazi Rule", "Adolf Hitler");
	 
	//Practices once
	ytChannel1.Practice();

	//Practices 5 times
	ytChannel2.Practice();
	ytChannel2.Practice();
	ytChannel2.Practice();
	ytChannel2.Practice();
	ytChannel2.Practice();

	YoutubeChannel* yt1 = &ytChannel1; 
	YoutubeChannel* yt2 = &ytChannel2;

	yt1->VideoAnalytics();
	yt2->VideoAnalytics();



	return 0;
}