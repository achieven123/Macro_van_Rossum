using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using Button = System.Windows.Forms.Button;

namespace Winforms_Calculator
{
    public partial class Form1 : Form
    {
        bool isClear = true;
        double result = 0;
        char op = '0';

        public Form1()
        {
            InitializeComponent();
        }

        //Numpad Click Event
        private void numpad_Click(object sender, EventArgs e)
        {
            if (isClear == true)
            {
                numBox2.Text = ((Button)sender).Text;

                if (numBox2.Text != "0") //0이 아닌 값이 들어왔을 때만 입력받기
                {
                    isClear = false;
                }
            }
            else
            {
                numBox2.Text += ((Button)sender).Text;
            }
        }

        //Delete Button Click Event
        private void backspace_Click(object sender, EventArgs e)
        {
            numBox2.Text = numBox2.Text.Substring(0, numBox2.Text.Length - 1);

            if (numBox2.Text.Length == 0)
            {
                numBox2.Text = "0";
                isClear = true;
                result = 0;
            }
        }

        //Clear Button Click Event
        private void clear_Click(object sender, EventArgs e)
        {
            numBox1.Text = "";
            numBox2.Text = "0";
            isClear = true;
            result = 0;
        }

        //Operator Button Click Event
        private void operator_Click(object sender, EventArgs e)
        {
            op = ((Button)sender).Text[0];
             MessageBox.Show(op.ToString());

            if (isClear == false)
            {
                //result += double.Parse(numBox2.Text);
                if (op == '+')
                {
                    MessageBox.Show("같음");
                    result += double.Parse(numBox2.Text);
                }
                //if (op == "-") result -= double.Parse(numBox2.Text);
                //if (op == "x") result *= double.Parse(numBox2.Text);
                //if (op == "÷") result /= double.Parse(numBox2.Text);
                //if (op == "%") result %= double.Parse(numBox2.Text);
            }

            numBox1.Text = result.ToString() + op;
            numBox2.Text = result.ToString();

            isClear = true;
        }
    }
}
