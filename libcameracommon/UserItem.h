
struct UserItem
{
	std::string Key;
	std::string Username;
	std::string Password;
	std::string EMail;

	time_t Created;
	time_t LastActivityDate;
	time_t LastLockoutDate;
	time_t LastLoginDate;
	time_t LastPasswordChange;

	bool IsApproved;
	bool IsLockedOut;
	bool IsOnline;
	
	int FailedPasswordAttempts;

	UserItem()
	{
		Uuid uuid = Uuid();
		Key = uuid.ToString();
		Username = "";
		Password = "";

		Created = 0;
		LastActivityDate = 0;
		LastLockoutDate = 0;
		LastLoginDate = 0;
		LastPasswordChange  = 0;

		IsApproved = false;
		IsLockedOut = false;
		IsOnline = false;
		
		FailedPasswordAttempts = 0;
	}
	
	bool ConfigLoad(Json::Value &json)
	{
		if (json.isMember("Key") == false)
			return false;		
		Key = json["Key"].asString();

		if (json.isMember("Username") == false)
			return false;
		Username = json["Username"].asString();

		if (json.isMember("Password") == false)
			return false;
		Password = json["Password"].asString();

		EMail = "";
		if (json.isMember("EMail") == true)
			EMail = json["EMail"].asString();

		Created = 0;
		if (json.isMember("Created") == true)
			Created = json["Created"].asInt();

		LastActivityDate = 0;
		if (json.isMember("LastActivityDate") == true)
			LastActivityDate = json["LastActivityDate"].asInt();

		LastLockoutDate = 0;
		if (json.isMember("LastLockoutDate") == true)
			LastLockoutDate = json["LastLockoutDate"].asInt();

		LastLoginDate = 0;
		if (json.isMember("LastLoginDate") == true)
			LastLoginDate = json["LastLoginDate"].asInt();

		LastPasswordChange = 0;
		if (json.isMember("LastPasswordChange") == true)
			LastPasswordChange = json["LastPasswordChange"].asInt();

		IsApproved = false;
		if (json.isMember("IsApproved") == true)
			IsApproved = json["IsApproved"].asBool();

		IsLockedOut = false;
		if (json.isMember("IsLockedOut") == true)
			IsLockedOut = json["IsLockedOut"].asBool();

		IsOnline = false;
		if (json.isMember("IsOnline") == true)
			IsLockedOut = json["IsOnline"].asBool();		
		
		FailedPasswordAttempts = 0;
		if (json.isMember("FailedPasswordAttempts") == true)
			FailedPasswordAttempts = json["LastPasswordChange"].asInt();

		return true;
	}

	bool ConfigSave(Json::Value &json)
	{
		json["Key"] = Key;
		json["Username"] = Username;
		json["Password"] = Password;
		json["EMail"] = EMail;

		json["Created"] = (int) Created;
		json["LastActivityDate"] = (int) LastActivityDate;
		json["LastLockoutDate"] = (int) LastLockoutDate;
		json["LastLoginDate"] = (int) LastLoginDate;
		json["LastPasswordChange"] = (int) LastPasswordChange;
		json["IsApproved"] = IsApproved;
		json["IsLockedOut"] = IsLockedOut;
		json["IsOnline"] = IsOnline;
		json["FailedPasswordAttempts"] = FailedPasswordAttempts;

		return true;
	}
	
	std::string Encode()
	{
		Json::Value json;
		ConfigSave(json);
		std::stringstream ss;
		Json::StyledWriter styledWriter;
		ss << styledWriter.write(json);
		return ss.str();
	}
	
	bool Decode(const std::string str)
	{
		Json::Value root;
                Json::Reader reader;

                if (reader.parse(str, root ) == false)
                        return false;
                
                try
                {
                	if (ConfigLoad(root) == false)
                		return false;
                }
                catch(...)
                {
                	return false;
                }
		return true;
	}
};

