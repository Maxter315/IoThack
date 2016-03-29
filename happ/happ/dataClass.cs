using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.WindowsAzure.Storage;
using Microsoft.WindowsAzure.Storage.Table;

namespace happ
{
            public class dataClass : TableEntity
        {
            public dataClass(string boxName, string boxNum)
            {
                this.PartitionKey = boxName;
            this.RowKey = boxNum;

        }

            public dataClass() { }

            public string temperature { get; set; }

            public string humidity { get; set; }
            public string lightsens { get; set; }
            public string door { get; set; }
    }
    
}
