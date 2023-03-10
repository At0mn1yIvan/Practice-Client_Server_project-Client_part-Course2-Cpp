#pragma once
#include <string>
#include "Patient.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class DataHandler
{
private:
	static std::string Packing(const Patient& p)   //To JSON
	{
		json toJson = json{ {"Firstname", p.GetFirstName()}, {"Lastname", p.GetLastName()}, {"Patronymic", p.GetPatronymic()}, {"State", p.GetState()}};
		return toJson.dump();
		
	}
	static std::string Packing(const VIP_Patient& vp)   //To JSON
	{
		json toJson = json{ {"Firstname", vp.GetFirstName()}, {"Lastname", vp.GetLastName()}, {"Patronymic", vp.GetPatronymic()}, {"State", vp.GetState()}, {"Money", vp.getMoney()}};
		return toJson.dump();
		
	}


	static Patient Unpacking(const std::string& str) // from JSON to data
	{
		json fromJson = json::parse(str);
		if (fromJson.contains("Money")) {
			return VIP_Patient(fromJson.at("Firstname"), fromJson.at("Lastname"), fromJson.at("Patronymic"), fromJson.at("State"), fromJson.at("Money"));
		}
		else{
			return Patient(fromJson.at("Firstname"), fromJson.at("Lastname"), fromJson.at("Patronymic"), fromJson.at("State"));
		
		}

	
	
	
	} 
};
