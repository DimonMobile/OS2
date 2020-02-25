using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace _2_.net
{
    class Program
    {
        [DllImport("../../../Debug/2_dll.dll")]
        public static extern int AddNumbers(int x, int y);
        [DllImport("../../../Debug/2_dll.dll")]
        public static extern uint GetTime();

        static void Main(string[] args)
        {
            Console.WriteLine($"Hello world {AddNumbers(1, 3)}");
            Console.WriteLine(GetTime());
            Console.Read();
        }
    }
}
