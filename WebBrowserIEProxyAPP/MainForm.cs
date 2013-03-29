using CookComputing.XmlRpc;
using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace WebBrowserIEProxyAPP
{
    public partial class MainForm : Form
    {
        IEProxy p = null;
        SHDocVw.WebBrowser wb;
        //string url = @"http://whatsmyuseragent.net/";
        //string url = "http://www.ip138.com/";
        string url = "http://www.ipreferrer.com/";
        string referer = @"Referer: http://www.baidu.com/s?wd=http%3A%2F%2Fwww.ipreferrer.com%2F&rsv_bp=0&ch=&tn=baidu&bar=&rsv_spt=3&ie=utf-8&rsv_n=2&rsv_sug3=1&rsv_sug1=1&rsv_sug4=38&inputT=1229";
        private IMath mathProxy;

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }

        public MainForm()
        {
            InitializeComponent();
            mathProxy = XmlRpcProxyGen.Create<IMath>();

        }

        private void WebBrowser_BeforeNavigate2(object pDisp, ref object URL, ref object Flags, ref object TargetFrameName, ref object PostData, ref object Headers, ref bool Cancel)
        {

            /*Console.WriteLine("wb url:" + URL);
            Console.WriteLine("Headers:" + Headers); //获取不了完整的headers头？
            string postDataText = System.Text.Encoding.ASCII.GetString(PostData as byte[]);
            Console.WriteLine(postDataText);
            Console.WriteLine("datas:");*/

        }

        private void HtmlDocument1_MouseOver(Object sender, HtmlElementEventArgs e)
        {
            //System.Diagnostics.Trace.WriteLine(e.ToElement.InnerHtml);
        }

        private void btn_ListenHTML_Click(object sender, EventArgs e)
        {
            p = new IEProxy(txt_Proxy.Text+":"+txt_ProxyPort.Text);

            wb = (SHDocVw.WebBrowser)webBrower1.ActiveXInstance;
            wb.BeforeNavigate2 += new SHDocVw.DWebBrowserEvents2_BeforeNavigate2EventHandler(WebBrowser_BeforeNavigate2);

            HtmlDocument htmlDoc = webBrower1.Document;
            htmlDoc.MouseOver += new HtmlElementEventHandler(HtmlDocument1_MouseOver);
            webBrower1.ScriptErrorsSuppressed = true;

            btn_localBrowser.Enabled = true;
            btn_ProxyBrowser.Enabled = true;
            btn_IE.Enabled = true;
            btn_Chrome.Enabled = true;
            btn_Foxfire.Enabled = true;
            btn_ListenHTML.Enabled = false;
        }

        private void btn_localBrowser_Click(object sender, EventArgs e)
        {
            bool result = p.DisableIEProxy();
            MessageBox.Show(result.ToString());
            webBrower1.Navigate(url);
        }

        private void btn_ProxyBrowser_Click(object sender, EventArgs e)
        {
            bool result = p.RefreshIESettings();
            MessageBox.Show(result.ToString());
            webBrower1.Navigate(url);
        }

        private void btn_IE_Click(object sender, EventArgs e)
        {
            string user_agent = "User-Agent: Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.1; Trident/6.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; .NET4.0C; .NET4.0E)";
            string accept = "Accept: image/jpeg, application/x-ms-application, image/gif, application/xaml+xml, image/pjpeg, application/x-ms-xbap, application/vnd.ms-excel, application/vnd.ms-powerpoint, application/msword, */* ";
            string accept_language = "Accept-Language: zh-CN";
            string dnt = "DNT: 1";

            //webBrowser1.Navigate(url, "_self", null, user_agent + "\n" + accept + "\n" + accept_language + "\n" + dnt);
            p.ChangeUserAgent(user_agent + "\n" + accept + "\n" + accept_language + "\n" + dnt);
            webBrower1.Navigate(url,null,null,referer);
        }

        private void btn_Chrome_Click(object sender, EventArgs e)
        {
            string user_agent = "User-Agent: Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.17 (KHTML, like Gecko) Chrome/24.0.1312.57 Safari/537.17";
            string accept = "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8";
            string accept_language = "Accept-Language: zh-CN,zh;q=0.8";
            string accept_charset = "Accept-Charset: GBK,utf-8;q=0.7,*;q=0.3";
            //webBrowser1.Navigate(url, "_self", null, user_agent + "\n" + accept + "\n" + accept_language + "\n" + accept_charset);
            p.ChangeUserAgent(user_agent + "\n" + accept + "\n" + accept_language + "\n" + accept_charset);
            webBrower1.Navigate(url, null, null, referer);
        }

        private void btn_Foxfire_Click(object sender, EventArgs e)
        {
            string user_agent = "User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9.2.12) Gecko/20101026 Firefox/3.6.12 QQDownload/1.7";
            string accept = "Accept: textml,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8 ";
            string accept_language = "Accept-Language: zh-cn,zh;q=0.8,en-us;q=0.5,en;q=0.3";
            //webBrowser1.Navigate(url, "_self", null, user_agent + "\n" + accept + "\n" + accept_language);
            p.ChangeUserAgent(user_agent + "\n" + accept + "\n" + accept_language);
            webBrower1.Navigate(url, null, null, referer);
        }

        private void btn_gotos_Click(object sender, EventArgs e)
        {
            webBrower1.Navigate(txt_url.Text);
        }

        private void btn_xml_rpc_Click(object sender, EventArgs e)
        {
            string xmp_rpc_rul = @"http://s5.runningproxy.com/blackhat_xmlrpc";
            mathProxy.Url = xmp_rpc_rul;

            try
            {
                object result = mathProxy.login("kelgood", "kelgood2");

                Hashtable table = result as Hashtable;
                Console.WriteLine("session_name:" + table["session_name"].ToString());
                Console.WriteLine("sessid:" + table["sessid"].ToString());
                IEProxy.InternetSetCookie(xmp_rpc_rul, "session_name", table["session_name"].ToString());
                IEProxy.InternetSetCookie(xmp_rpc_rul, "sessid", table["sessid"].ToString());


                
            }
            catch (Exception ex)
            {
                Console.WriteLine("ex:" + ex.Message.ToString());
            }
            
        }

        public interface IMath : IXmlRpcProxy
        {
            [XmlRpcMethod("user.login")]
            object login(string username, string password);

            [XmlRpcMethod("blackhat_3rd_party.getProxyListA")]
            object getProxyListA(
                string useragent,
                string country,
                string region,
                int limit,
                int page);
        }
    }
}
