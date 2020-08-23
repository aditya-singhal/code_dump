using System;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            MassClient Client;
			
			string server_ip = "192.168.2.20";
			string user_name = "admin";
			string password = "password";
			Client = new MassClient(server_ip, user_name, password);
        }
    }
}
