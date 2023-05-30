using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Winforms_Calculator
{
    public partial class Form1 : Form
    {
        bool isClear = true;

        public Form1()
        {
            InitializeComponent();
        }

        private void numpad_Click(object sender, EventArgs e)
        {
            Button btn = sender as Button;

            if (isClear == true)
            {
                numBox.Text = 
            }
        }
    }
}
