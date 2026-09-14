namespace symulatorSejfu
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.TextBox txtPin;
        private System.Windows.Forms.Label lblStatus;
        private System.Windows.Forms.Button btnOtworz;
        private System.Windows.Forms.Button btnUstawKod;
        private System.Windows.Forms.Button btnSkasujKod;
        private System.Windows.Forms.Button btnWyczysc;
        private System.Windows.Forms.FlowLayoutPanel panelNumeryczny;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null)) components.Dispose();
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            this.txtPin = new System.Windows.Forms.TextBox();
            this.lblStatus = new System.Windows.Forms.Label();
            this.btnOtworz = new System.Windows.Forms.Button();
            this.btnUstawKod = new System.Windows.Forms.Button();
            this.btnSkasujKod = new System.Windows.Forms.Button();
            this.btnWyczysc = new System.Windows.Forms.Button();
            this.panelNumeryczny = new System.Windows.Forms.FlowLayoutPanel();
            this.SuspendLayout();
            // 
            // txtPin
            // 
            this.txtPin.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.txtPin.Location = new System.Drawing.Point(12, 12);
            this.txtPin.Name = "txtPin";
            this.txtPin.PasswordChar = '*';
            this.txtPin.Size = new System.Drawing.Size(260, 29);
            this.txtPin.TabIndex = 0;
            this.txtPin.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // panelNumeryczny
            // 
            this.panelNumeryczny.Location = new System.Drawing.Point(12, 50);
            this.panelNumeryczny.Name = "panelNumeryczny";
            this.panelNumeryczny.Size = new System.Drawing.Size(180, 150);
            this.panelNumeryczny.TabIndex = 1;
            // Dodawanie przycisków 1-9 i 0
            for (int i = 1; i <= 10; i++)
            {
                System.Windows.Forms.Button b = new System.Windows.Forms.Button();
                b.Text = (i % 10).ToString();
                b.Size = new System.Drawing.Size(50, 40);
                b.Click += new System.EventHandler(this.ButtonCyfra_Click);
                this.panelNumeryczny.Controls.Add(b);
            }
            // 
            // btnOtworz
            // 
            this.btnOtworz.Location = new System.Drawing.Point(198, 50);
            this.btnOtworz.Name = "btnOtworz";
            this.btnOtworz.Size = new System.Drawing.Size(75, 30);
            this.btnOtworz.Text = "Otwórz";
            this.btnOtworz.Click += new System.EventHandler(this.btnOtworz_Click);
            // 
            // btnUstawKod
            // 
            this.btnUstawKod.Location = new System.Drawing.Point(198, 86);
            this.btnUstawKod.Name = "btnUstawKod";
            this.btnUstawKod.Size = new System.Drawing.Size(75, 30);
            this.btnUstawKod.Text = "Ustaw";
            this.btnUstawKod.Click += new System.EventHandler(this.btnUstawKod_Click);
            // 
            // btnSkasujKod
            // 
            this.btnSkasujKod.Location = new System.Drawing.Point(198, 122);
            this.btnSkasujKod.Name = "btnSkasujKod";
            this.btnSkasujKod.Size = new System.Drawing.Size(75, 30);
            this.btnSkasujKod.Text = "Skasuj";
            this.btnSkasujKod.Click += new System.EventHandler(this.btnSkasujKod_Click);
            // 
            // btnWyczysc
            // 
            this.btnWyczysc.Location = new System.Drawing.Point(198, 158);
            this.btnWyczysc.Name = "btnWyczysc";
            this.btnWyczysc.Size = new System.Drawing.Size(75, 30);
            this.btnWyczysc.Text = "Wyczyść";
            this.btnWyczysc.Click += new System.EventHandler(this.btnWyczysc_Click);
            // 
            // lblStatus
            // 
            this.lblStatus.Location = new System.Drawing.Point(12, 210);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(260, 40);
            this.lblStatus.Text = "Status: Brak kodu";
            this.lblStatus.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.lblStatus);
            this.Controls.Add(this.btnWyczysc);
            this.Controls.Add(this.btnSkasujKod);
            this.Controls.Add(this.btnUstawKod);
            this.Controls.Add(this.btnOtworz);
            this.Controls.Add(this.panelNumeryczny);
            this.Controls.Add(this.txtPin);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Sejf Elektroniczny";
            this.ResumeLayout(false);
            this.PerformLayout();
        }
    }
}