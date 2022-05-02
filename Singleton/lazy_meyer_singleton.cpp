#include <iostream>
#include <string>
#include <vector>
/*
 * Singleton == only one instance with global access 
*/
class Logger{
    public:
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        static Logger& GetInstance(){
            static Logger instance;
            return instance;
        }

        static void Add(const std::string& s){ GetInstance().AddImpl(s);}
        static void Print(){ GetInstance().PrintImpl(); }
   
    private:
        Logger(){std::cout << "LOG()\n";} // doesnt allow to create multi instances
        ~Logger(){std::cout << "~LOG()\n";}
        void AddImpl(const std::string& s){ m_messages.push_back(s);}
        void PrintImpl(){ 
            std::cout << "Accesing logger:" << std::endl;
            for(const auto& e: m_messages) std::cout << e << std::endl;
        }
        std::vector<std::string> m_messages;
};

int main(int argc, char** argv){
    Logger& l = Logger::GetInstance();
    l.Add("Added before first");
    Logger::Add("Log first line");
    Logger::Add("Additional line");
    Logger::Print();
}