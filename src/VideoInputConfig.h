
class VideoInputConfig
{
	public:
		VideoInputConfig();
		~VideoInputConfig();

		std::string ToStr() const;

		bool ConfigSave(Json::Value &json);
		bool ConfigLoad(Json::Value &json);

		int GetFrameRate();
		void SetFrameRate(int fps);

		std::string GetCodec();
		void SetCodec(const std::string &str);

		std::string GetResolution();
		void SetResolution(const std::string &str);

		int GetWidth();
		int GetHeight();

		bool GetEnabled();
		void SetEnabled(bool enabled);

		int hflip;
		int vflip;

		//FIXME: Codec Options eg bitrate, maxbitrate, vbr/cbr etc..
		
		
		std::string Encode();
		bool Decode(const std::string);

	private:
		int m_framerate;
		std::string m_codec;
		std::string m_resolution;
		bool m_enabled;

};

