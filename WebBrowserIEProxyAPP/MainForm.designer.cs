namespace WebBrowserIEProxyAPP
{
    partial class MainForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.webBrower1 = new System.Windows.Forms.WebBrowser();
            this.btn_ListenHTML = new System.Windows.Forms.Button();
            this.btn_localBrowser = new System.Windows.Forms.Button();
            this.btn_ProxyBrowser = new System.Windows.Forms.Button();
            this.btn_IE = new System.Windows.Forms.Button();
            this.btn_Chrome = new System.Windows.Forms.Button();
            this.btn_Foxfire = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.txt_url = new System.Windows.Forms.TextBox();
            this.btn_gotos = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txt_ProxyPort = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txt_Proxy = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.btn_xml_rpc = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // webBrower1
            // 
            this.webBrower1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.webBrower1.Location = new System.Drawing.Point(12, 144);
            this.webBrower1.MinimumSize = new System.Drawing.Size(20, 20);
            this.webBrower1.Name = "webBrower1";
            this.webBrower1.Size = new System.Drawing.Size(598, 244);
            this.webBrower1.TabIndex = 0;
            this.webBrower1.Url = new System.Uri("", System.UriKind.Relative);
            // 
            // btn_ListenHTML
            // 
            this.btn_ListenHTML.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btn_ListenHTML.Location = new System.Drawing.Point(22, 403);
            this.btn_ListenHTML.Name = "btn_ListenHTML";
            this.btn_ListenHTML.Size = new System.Drawing.Size(122, 23);
            this.btn_ListenHTML.TabIndex = 1;
            this.btn_ListenHTML.Text = "初使化监听html属性";
            this.btn_ListenHTML.UseVisualStyleBackColor = true;
            this.btn_ListenHTML.Click += new System.EventHandler(this.btn_ListenHTML_Click);
            // 
            // btn_localBrowser
            // 
            this.btn_localBrowser.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btn_localBrowser.Enabled = false;
            this.btn_localBrowser.Location = new System.Drawing.Point(151, 403);
            this.btn_localBrowser.Name = "btn_localBrowser";
            this.btn_localBrowser.Size = new System.Drawing.Size(84, 23);
            this.btn_localBrowser.TabIndex = 2;
            this.btn_localBrowser.Text = "本地浏览";
            this.btn_localBrowser.UseVisualStyleBackColor = true;
            this.btn_localBrowser.Click += new System.EventHandler(this.btn_localBrowser_Click);
            // 
            // btn_ProxyBrowser
            // 
            this.btn_ProxyBrowser.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btn_ProxyBrowser.Enabled = false;
            this.btn_ProxyBrowser.Location = new System.Drawing.Point(242, 403);
            this.btn_ProxyBrowser.Name = "btn_ProxyBrowser";
            this.btn_ProxyBrowser.Size = new System.Drawing.Size(107, 23);
            this.btn_ProxyBrowser.TabIndex = 3;
            this.btn_ProxyBrowser.Text = "socket5代理浏览";
            this.btn_ProxyBrowser.UseVisualStyleBackColor = true;
            this.btn_ProxyBrowser.Click += new System.EventHandler(this.btn_ProxyBrowser_Click);
            // 
            // btn_IE
            // 
            this.btn_IE.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btn_IE.Enabled = false;
            this.btn_IE.Location = new System.Drawing.Point(356, 403);
            this.btn_IE.Name = "btn_IE";
            this.btn_IE.Size = new System.Drawing.Size(75, 23);
            this.btn_IE.TabIndex = 4;
            this.btn_IE.Text = "IE";
            this.btn_IE.UseVisualStyleBackColor = true;
            this.btn_IE.Click += new System.EventHandler(this.btn_IE_Click);
            // 
            // btn_Chrome
            // 
            this.btn_Chrome.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btn_Chrome.Enabled = false;
            this.btn_Chrome.Location = new System.Drawing.Point(438, 403);
            this.btn_Chrome.Name = "btn_Chrome";
            this.btn_Chrome.Size = new System.Drawing.Size(75, 23);
            this.btn_Chrome.TabIndex = 5;
            this.btn_Chrome.Text = "Chrome";
            this.btn_Chrome.UseVisualStyleBackColor = true;
            this.btn_Chrome.Click += new System.EventHandler(this.btn_Chrome_Click);
            // 
            // btn_Foxfire
            // 
            this.btn_Foxfire.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btn_Foxfire.Enabled = false;
            this.btn_Foxfire.Location = new System.Drawing.Point(520, 403);
            this.btn_Foxfire.Name = "btn_Foxfire";
            this.btn_Foxfire.Size = new System.Drawing.Size(75, 23);
            this.btn_Foxfire.TabIndex = 6;
            this.btn_Foxfire.Text = "Foxfrie";
            this.btn_Foxfire.UseVisualStyleBackColor = true;
            this.btn_Foxfire.Click += new System.EventHandler(this.btn_Foxfire_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 36);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 7;
            this.label1.Text = "地址：";
            // 
            // txt_url
            // 
            this.txt_url.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_url.Location = new System.Drawing.Point(57, 32);
            this.txt_url.Name = "txt_url";
            this.txt_url.Size = new System.Drawing.Size(484, 21);
            this.txt_url.TabIndex = 8;
            this.txt_url.Text = "http://whatsmyuseragent.net/";
            // 
            // btn_gotos
            // 
            this.btn_gotos.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_gotos.Location = new System.Drawing.Point(548, 31);
            this.btn_gotos.Name = "btn_gotos";
            this.btn_gotos.Size = new System.Drawing.Size(53, 23);
            this.btn_gotos.TabIndex = 9;
            this.btn_gotos.Text = "gotos";
            this.btn_gotos.UseVisualStyleBackColor = true;
            this.btn_gotos.Click += new System.EventHandler(this.btn_gotos_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.txt_url);
            this.groupBox1.Controls.Add(this.btn_gotos);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(6, 6);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(609, 74);
            this.groupBox1.TabIndex = 10;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Web";
            // 
            // groupBox2
            // 
            this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox2.Controls.Add(this.txt_ProxyPort);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.txt_Proxy);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Location = new System.Drawing.Point(6, 86);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(609, 52);
            this.groupBox2.TabIndex = 11;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Socket5代理";
            // 
            // txt_ProxyPort
            // 
            this.txt_ProxyPort.Location = new System.Drawing.Point(269, 24);
            this.txt_ProxyPort.Name = "txt_ProxyPort";
            this.txt_ProxyPort.Size = new System.Drawing.Size(128, 21);
            this.txt_ProxyPort.TabIndex = 3;
            this.txt_ProxyPort.Text = "8087";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(222, 27);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(41, 12);
            this.label3.TabIndex = 2;
            this.label3.Text = "端口：";
            // 
            // txt_Proxy
            // 
            this.txt_Proxy.Location = new System.Drawing.Point(73, 24);
            this.txt_Proxy.Name = "txt_Proxy";
            this.txt_Proxy.Size = new System.Drawing.Size(128, 21);
            this.txt_Proxy.TabIndex = 1;
            this.txt_Proxy.Text = "127.0.0.1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(14, 27);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 0;
            this.label2.Text = "IP地址：";
            // 
            // btn_xml_rpc
            // 
            this.btn_xml_rpc.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btn_xml_rpc.Location = new System.Drawing.Point(22, 447);
            this.btn_xml_rpc.Name = "btn_xml_rpc";
            this.btn_xml_rpc.Size = new System.Drawing.Size(137, 23);
            this.btn_xml_rpc.TabIndex = 12;
            this.btn_xml_rpc.Text = "xml_rpc[user.login]";
            this.btn_xml_rpc.UseVisualStyleBackColor = true;
            this.btn_xml_rpc.Click += new System.EventHandler(this.btn_xml_rpc_Click);
            // 
            // button1
            // 
            this.button1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button1.Location = new System.Drawing.Point(165, 447);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(266, 23);
            this.button1.TabIndex = 13;
            this.button1.Text = "xml_rpc[blackhat_3rd_party.getProxyListA]";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(622, 502);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btn_Foxfire);
            this.Controls.Add(this.btn_Chrome);
            this.Controls.Add(this.btn_IE);
            this.Controls.Add(this.btn_ProxyBrowser);
            this.Controls.Add(this.btn_localBrowser);
            this.Controls.Add(this.btn_ListenHTML);
            this.Controls.Add(this.webBrower1);
            this.Controls.Add(this.btn_xml_rpc);
            this.Controls.Add(this.button1);
            this.Name = "MainForm";
            this.Text = "代理---User-Agent模拟";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.WebBrowser webBrower1;
        private System.Windows.Forms.Button btn_ListenHTML;
        private System.Windows.Forms.Button btn_localBrowser;
        private System.Windows.Forms.Button btn_ProxyBrowser;
        private System.Windows.Forms.Button btn_IE;
        private System.Windows.Forms.Button btn_Chrome;
        private System.Windows.Forms.Button btn_Foxfire;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txt_url;
        private System.Windows.Forms.Button btn_gotos;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txt_Proxy;
        private System.Windows.Forms.TextBox txt_ProxyPort;
        private System.Windows.Forms.Button btn_xml_rpc;
        private System.Windows.Forms.Button button1;
    }
}

