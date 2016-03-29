using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using Microsoft.WindowsAzure.Storage;
using Microsoft.WindowsAzure.Storage.Auth;
using Microsoft.WindowsAzure.Storage.Table;
using System.Configuration;
using Microsoft.WindowsAzure.ServiceRuntime;


namespace happ
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] delimiterChars = { ' ','\t' };

            CloudStorageAccount storageAccount = CloudStorageAccount.Parse(
            ConfigurationManager.AppSettings["StorageConnectionString"]);

            // Create the table client.
            CloudTableClient tableClient = storageAccount.CreateCloudTableClient();

            // Create the table if it doesn't exist.
            CloudTable table = tableClient.GetTableReference("BoxTab");
            table.CreateIfNotExists();

            SerialPort serialport1 = new SerialPort();
            serialport1.BaudRate = 115200;
            serialport1.PortName = "COM10";
            serialport1.Open();

            while (true)
            {
                string data_rx = serialport1.ReadLine();
                
                DateTime thisDay = DateTime.Now;
                Console.WriteLine(thisDay); Console.WriteLine(data_rx);
                string[] words = data_rx.Split(delimiterChars);
                dataClass box1 = new dataClass("box1a", thisDay.ToString("u"));
                box1.temperature = words[1];
                box1.humidity = words[0];
                box1.lightsens = words[2];
                box1.door = words[3];
                TableOperation insertOperation = TableOperation.Insert(box1);
                table.Execute(insertOperation);
            }
        }
    }
}
