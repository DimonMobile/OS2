using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int k = axMy21.TestMyMethod(4, 4, "HI");
            MessageBox.Show(k.ToString(), "Kek"); ;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int k = axMy21.TestMyMethod(Int32.Parse(textBox1.Text), 4, "HI");
            textBox2.Text = k.ToString();
        }
    }
}
