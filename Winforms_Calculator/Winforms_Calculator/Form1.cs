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
        bool isOperand = false;
        double result = 0;
        string op = "";

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

                //0이 아닌 값이 들어왔을 때만 입력받기
                if (numBox2.Text != "0")
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
            if (isClear == false && op != "") //피연산자와 전에 입력된 연산자가 있을 경우 연산 수행
            {
                switch (op)
                {
                    case "＋":
                        result += double.Parse(numBox2.Text);
                        break;
                    case "－":
                        result -= double.Parse(numBox2.Text);
                        break;
                    case "×":
                        result *= double.Parse(numBox2.Text);
                        break;
                    case "÷":
                        result /= double.Parse(numBox2.Text);
                        break;
                    case "%":
                        result %= double.Parse(numBox2.Text);
                        break;
                }
            }
            else
            {
                result = double.Parse(numBox2.Text);
            }

            op = ((Button)sender).Text;
            numBox1.Text = result.ToString() + op;
            numBox2.Text = result.ToString();
            isClear = true;
        }
    }
}
