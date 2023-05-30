using System;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Winforms_Calculator
{
    public partial class Form1 : Form
    {
        bool isClear = true;


        public Form1()
        {
            InitializeComponent();
        }

        //Numpad Click Event
        private void numpad_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.Button btn = sender as System.Windows.Forms.Button;

            if (isClear == true)
            {
                numBox2.Text = btn.Text;
                if (numBox2.Text != "0") isClear = false;
            }
            else
            {
                numBox2.Text += btn.Text;
            }
        }

        //Delete Button Click Event
        private void backspace_Click(object sender, EventArgs e)
        {
            numBox2.Text = numBox2.Text.Substring(0, numBox2.Text.Length - 1);

            if (numBox2.Text.Length == 0) {
                numBox2.Text = "0";
                isClear = true;
            }
        }

        //Clear Button Click Event
        private void clear_Click(object sender, EventArgs e)
        {
            numBox1.Text = "";
            numBox2.Text = "0";
            isClear = true;
        }

        //Operator Button Click Event
        private void operator_Click(object sender, EventArgs e)
        {
            string name = ((System.Windows.Forms.Button)sender).Name;

            switch (name)
            {
                case "plus":
                    numBox1.Text += numBox2.Text;
                    numBox1.Text += "+";
                    break;
                case "minus":
                    numBox1.Text += numBox2.Text;
                    numBox1.Text += "-";
                    break;
                case "product":
                    numBox1.Text += numBox2.Text;
                    numBox1.Text += "x";
                    break;
                case "divide":
                    numBox1.Text += numBox2.Text;
                    numBox1.Text += "/";
                    break;
                case "remainder":
                    numBox1.Text += numBox2.Text;
                    numBox1.Text += "%";
                    break;
                case "negate":
                    break;
            }
        }
    }
}
