
class User
{
	public:
		static bool Init();
		static void Destroy();
		static bool ConfigLoad(Json::Value &json);
		static bool ConfigSave(Json::Value &json);

		static int Create(const std::string User, const std::string Password, const std::string EMail);
		static bool Auth(const std::string User, const std::string Password);
		static int Delete(const std::string User);
		static int Exists(const std::string User);
		static int SetPassword(const std::string User, const std::string Password);
		static int Touch(const std::string User);

		static int IsLockedOut(const std::string User);
		static int IsApproved(const std::string User);
		static int IsOnline(const std::string User);
		
		static int SetLockedOut(const std::string User, bool value);
		static int SetApproved(const std::string User, bool value);
		
		static int GetLockoutDuration();
		static int SetLockoutDuration(int value);
		
		static int GetMaxFailedAttempts();
		static int SetMaxFailedAttempts(int value);
		
		static int GetAutoLogOff();
		static int SetAutoLogOff(int value);

		static int GetUserFromEMail(const std::string EMail, std::string *User);
		static int GetUserFromKey(const std::string Key, std::string *User);
		
		static int UserInfo(const std::string User, UserItem *);

		static std::vector<std::string> List();

		static void Lock();
		static void Unlock();
		
	protected:
		static void Reset();
		static void ProcessUnlock(void *);
		static void ProcessLogoff(void *);


	private:
		static Mutex m_mutex;
		static std::map<std::string, UserItem *> m_map;
		static int m_lockoutduration;
		static int m_maxattempts;
		static int m_autologoff;
		
		static TimerFunc *m_TmrLockout;
		static TimerFunc *m_TmrLogOff;

};

