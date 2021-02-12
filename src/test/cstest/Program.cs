using System;
using System.Runtime.InteropServices;
using System.Text;

namespace cs
{
    class Program
    {

        [StructLayout(LayoutKind.Sequential)]
        struct TEST_SCHEMA
        {
            public int int1;

            public int int2;

            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 32)]
            public byte[] _testChar;

            public string testChar
            {
                get
                {
                    return Encoding.UTF8.GetString(_testChar).TrimEnd((Char)0);
                }
            }
        }

        [DllImport("libdasample")]
        private static extern int refer(out TEST_SCHEMA schema);

        static void Main(string[] args)
        {
            int rtc = refer(out TEST_SCHEMA schema);

            Console.WriteLine($"{rtc} {schema.int1} {schema.int2} {schema.testChar}");
        }
    }
}
