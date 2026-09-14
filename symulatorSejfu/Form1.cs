using System;
using System.Drawing;
using System.Windows.Forms;

namespace symulatorSejfu
{
    public partial class Form1 : Form
    {
        private string zapisanyKod = null;
        private int bledneProby = 0;

        public Form1()
        {
            InitializeComponent();
            AktualizujStatus("Sejf nowo uruchomiony. Brak ustawionego kodu.");
        }

        private void ButtonCyfra_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;
            txtPin.Text += btn.Text;
        }

        private void btnUstawKod_Click(object sender, EventArgs e)
        {
            string wpisanyKod = txtPin.Text;

            if (string.IsNullOrEmpty(wpisanyKod) || wpisanyKod.Length < 4)
            {
                AktualizujStatus("Błąd: Kod musi mieć co najmniej 4 cyfry.");
                return;
            }

            if (zapisanyKod != null)
            {
                AktualizujStatus("Kod jest już ustawiony. Najpierw go skasuj.");
                return;
            }

            zapisanyKod = wpisanyKod;
            AktualizujStatus("Kod został ustawiony.");
            WyczyscPole();
        }

        private void btnOtworz_Click(object sender, EventArgs e)
        {
            if (zapisanyKod == null)
            {
                AktualizujStatus("Błąd: Sejf nie ma ustawionego kodu.");
                return;
            }

            if (txtPin.Text == zapisanyKod)
            {
                AktualizujStatus("Sejf otwarty.");
                bledneProby = 0; 
            }
            else
            {
                bledneProby++;
                if (bledneProby >= 3)
                {
                    AktualizujStatus("Alarm! Trzy błędne próby.");
                }
                else
                {
                    AktualizujStatus($"Błędny kod. Sejf zamknięty. (Próba {bledneProby}/3)");
                }
            }
            WyczyscPole();
        }

        private void btnSkasujKod_Click(object sender, EventArgs e)
        {
            if (zapisanyKod == null)
            {
                AktualizujStatus("Błąd: Brak kodu do skasowania.");
                return;
            }

            if (txtPin.Text == zapisanyKod)
            {
                zapisanyKod = null;
                bledneProby = 0;
                AktualizujStatus("Kod został skasowany.");
                WyczyscPole();
            }
            else
            {
                AktualizujStatus("Podaj poprawny kod, aby go skasować.");
            }
        }

        private void btnWyczysc_Click(object sender, EventArgs e)
        {
            WyczyscPole();
        }

        private void WyczyscPole()
        {
            txtPin.Clear();
        }

        private void AktualizujStatus(string tresc)
        {
            lblStatus.Text = "Status: " + tresc;
        }
    }
}