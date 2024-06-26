module ThunderEngine.Logger;

namespace ThunderEngine
{
	void Logger::LogPreMessage(LogMessageType message_type)
	{
		LogTimestamp();
		LogStyleAndTypeName(message_type);
	}

	void Logger::LogTimestamp()
	{
		auto now = std::chrono::system_clock::now().time_since_epoch();
		auto now_milli = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
		int millis = now_milli % 1000;

		int time_today = (now_milli / 1000) % (24 * 60 * 60); // Seconds since 00:00:00 today
		int seconds = time_today % 60;
		int minutes = (time_today % (60 * 60)) / 60;
		int hours = (time_today / (60 * 60));

		std::cout << "[" 
			<< std::setfill('0') << std::setw(2) << hours 
			<< ":" << std::setw(2) << minutes
			<< ":" << std::setw(2) << seconds 
			<< "." << std::setw(3) << millis
			<< "] ";
	}

	void Logger::LogStyleAndTypeName(LogMessageType message_type)
	{
		switch (message_type)
		{
		case LogMessageType::INFO:
			std::cout << CYAN << "[INFO] ";
			break;
		case LogMessageType::WARNING:
			std::cout << YELLOW << "[WARN] ";
			break;
		case LogMessageType::ERROR:
			std::cout << RED << "[ERROR] ";
			break;
		}
	}
}
