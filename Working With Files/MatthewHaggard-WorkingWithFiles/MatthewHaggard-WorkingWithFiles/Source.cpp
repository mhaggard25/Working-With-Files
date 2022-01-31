/* 
* Name: Matthew Haggard
* Module 4 assignment - Working with files
* Date: 01/30/2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Create a class for City
class City {
public:
	// Create setters for the the name and temperature.
	void setCityName(string nameOfCity) {
		cityName = nameOfCity;
	}

	void setCityTemp(int tempOfCity) {
		cityTemp = tempOfCity;
	}

	// Create getters for name and temperature
	string getCityName() const{
		return cityName;
	}

	int getCityTemp() const{
		return cityTemp;
	}

private:
	string cityName = "Default";
	int cityTemp = 0;
};

// Function to read information from the file.
void ReadCityInfo(vector<City>& listOfCities ) {
	ifstream inFile;
	string nameOfMyCity;
	int myTemperature;
	City myCity;

	// Open the text file.
	inFile.open("FahrenheitTemperature.txt");

	// Display user feedback
	cout << "Opening file..." << endl;

	// Ensure the file is open
	if (!inFile.is_open()) {
		cout << "The file could not be opened." << endl;
	}

	// Read the file until the end.
	while (!inFile.eof()) {
		inFile >> nameOfMyCity;
		inFile >> myTemperature;

		// As long as the read is successful, set the city name and temperature and use push_back to add it to the vector.
		if (!inFile.fail()) {
			myCity.setCityName(nameOfMyCity);
			myCity.setCityTemp(myTemperature);
			listOfCities.push_back(myCity);
		}
	}

	// Close the file.
	inFile.close();

}

// function to convert the fahrenheit temp to celsius
double ConvertToCelsius(const int temp) {

	double celsiusValue;

	celsiusValue = (temp - 32) * (5.0 / 9.0);

	return celsiusValue;

}

void WriteCityInfo(vector<City>& listOfCities) {
	ofstream outFile;
	outFile.open("CelsiusTemperature.txt");

	if (!outFile.is_open()) {
		cout << "Could not open file for writing..." << endl;
	}

	else {
		cout << "Writing data to file..." << endl;
	}

	for (int i = 0; i < listOfCities.size(); i++) {
		outFile << listOfCities.at(i).getCityName() << " " << ConvertToCelsius(listOfCities.at(i).getCityTemp()) << endl;
	}
	


	outFile.close();
}



int main() {

	// Create a vector of type city for a list of cities
	vector<City> listOfCities;

	// Read the info from the provided file
	ReadCityInfo(listOfCities);

	// Write the new converted infor to a new file
	WriteCityInfo(listOfCities);

	return 0;
}