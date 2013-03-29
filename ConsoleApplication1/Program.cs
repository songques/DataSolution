using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {

        [DllImport("RegeditHrefLibrary.dll", EntryPoint = "Dll_Mul", CallingConvention = CallingConvention.Cdecl)]
        private static extern int Dll_Mul(int num1, int num2);

        [DllImport("RegeditHrefLibrary.dll", EntryPoint = "RegeditHrefValue", CallingConvention = CallingConvention.Cdecl)]
        private static extern int RegeditHrefValue(string str1, string str2,out string str3);

        [DllImport("RegeditHrefLibrary.dll", EntryPoint = "Regsvr32Href", CallingConvention = CallingConvention.Cdecl)]
        private static extern int Regsvr32Href(string path);

        

        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("启动");
                //bool result=RegeditHrefContext("abc");
                //Console.WriteLine(result);
                //int num3 = Dll_Mul(1, 2);
                //Console.WriteLine(num3);

                //string str3 = null;
                //RegeditHrefValue("a", "b", out str3);
                //Console.WriteLine(str3);

                int nRet = Regsvr32Href("CSSIM");
                Console.WriteLine("注册表操作完成：" + nRet);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine("结束");
            Console.ReadKey();
        }
    }
}
