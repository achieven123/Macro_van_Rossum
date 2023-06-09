using System;
using System.Runtime.CompilerServices;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using Button = System.Windows.Forms.Button;

namespace Winforms_Calculator
{
    public partial class Form1 : Form
    {
        bool isExist = false;           //numBox2.Text 존재 여부 확인
        bool isFirst = false;           //첫번째 피연산자, 연산자 입력 여부 확인
        bool isSecond = false;          //두번째 피연산자 입력 여부 확인
        decimal first, second, result;  //피연산자1, 피연산자2, 연산 결과 저장
        decimal memory = 0;
        string operation;

        public Form1()
        {
            InitializeComponent();
        }

        //Numpad Click Event
        private void numpad_Click(object sender, EventArgs e)
        {
            if (isFirst == true)
            {
                isSecond = true;
            }
            else
            {
                numBox1.Text = "";
            }

            if (isExist == false)   //피연산자가 존재하지 않을 때 입력이 된다면
            {
                numBox2.Text = "0"; //0으로 초기화
                isExist = true;
            }

            //첫번째 입력 숫자가 0이 아닐 때만 입력 받기
            if (numBox2.Text == "0")
            {
                numBox2.Text = ((Button)sender).Text;
            }
            else
            {
                numBox2.Text += ((Button)sender).Text;
            }
        }

        //Clear Entry Button Click Event
        private void clearEntry_Click(object sender, EventArgs e)
        {
            numBox2.Text = "0";
            isExist = false;
            isSecond = false;
        }

        //Clear Button Click Event
        private void clear_Click(object sender, EventArgs e)
        {
            numBox1.Text = "";
            numBox2.Text = "0";
            isExist = false;
            isFirst = isSecond = false;
            first = second = result = 0.0m;
        }

        //Delete Button Click Event
        private void backspace_Click(object sender, EventArgs e)
        {
            if (isExist == true)
            {
                numBox2.Text = numBox2.Text.Substring(0, numBox2.Text.Length - 1);

                //numBox2.Text의 길이가 0이라면, 계속 0으로 유지
                if (numBox2.Text.Length == 0)
                {
                    numBox2.Text = "0";
                }
            }
        }

        //Operator1 Button Click Event
        private void operator1_Click(object sender, EventArgs e)
        {
            decimal x = decimal.Parse(numBox2.Text);
            string temp = ((Button)sender).Text;

            switch (temp) //연산자에 따라 계산
            {
                case "1/x":
                    try
                    {
                        x = 1 / x;
                        numBox2.Text = x.ToString();
                    }
                    catch (System.DivideByZeroException)
                    {
                        numBox2.Text = "N/A"; //0으로 나눌 때 예외처리
                    }
                    break;
                case "1/x²":
                    try
                    {
                        x = 1 / (x * x);
                        numBox2.Text = x.ToString();
                    }
                    catch (System.DivideByZeroException)
                    {
                        numBox2.Text = "N/A"; //0으로 나눌 때 예외처리
                    }
                    break;
                case "²√x":
                    x = Convert.ToDecimal(Math.Sqrt(Convert.ToDouble(x)));
                    numBox2.Text = x.ToString();
                    break;
                case "＋/－":
                    x = (-1) * x;
                    numBox2.Text = x.ToString();
                    break;
                case ".":
                    if (!numBox2.Text.Contains("."))
                    {
                        numBox2.Text += ".";
                        isExist = true;
                    }
                    break;
            }
        }

        //Operator2 Button Click Event
        private void operator2_Click(object sender, EventArgs e)
        {
            if (isFirst == true && isSecond == true)    //피연산자와 연산자가 모두 존재하면
            {
                equal.PerformClick();                   //Equal 클릭 이벤트
                first = result;
            }
            else
            {
                first = decimal.Parse(numBox2.Text);
            }
            
            operation = ((Button)sender).Text;
            numBox1.Text = first.ToString() + operation;
            isFirst = true;
            isExist = false;
        }

        //Equal Button Click Event
        private void equal_Click(object sender, EventArgs e)
        {
            if (isFirst == true && isSecond == true)    //피연산자와 연산자가 모두 존재하면
            {
                second = decimal.Parse(numBox2.Text);   //두번째 피연산자에 numBox2.Text 값 할당

                switch (operation) //연산자에 따른 계산
                {
                    case "＋":
                        result = first + second;
                        numBox2.Text = result.ToString();
                        break;
                    case "－":
                        result = first - second;
                        numBox2.Text = result.ToString();
                        break;
                    case "×":
                        result = first * second;
                        numBox2.Text = result.ToString();
                        break;
                    case "÷":
                        try
                        {
                            result = first / second;
                            numBox2.Text = result.ToString();
                        }
                        catch (System.DivideByZeroException)
                        {
                            numBox2.Text = "N/A"; //0으로 나눌 때 예외처리
                        }
                        break;
                    case "%":
                        result = first % second;
                        numBox2.Text = result.ToString();
                        break;
                }

                numBox1.Text = first + operation + second + " = ";

                isFirst = isSecond =  false;
                isExist = false;
            }
        }

        //Memory Button Click Event
        private void memory_Click(object sender, EventArgs e)
        {
            decimal num = decimal.Parse(numBox2.Text);
            string temp = ((Button)sender).Text;

            switch (temp)
            {
                case "MC":
                    memory = 0;
                    break;
                case "MR":
                    numBox2.Text = memory.ToString();
                    break;
                case "M+":
                    memory += num;
                    break;
                case "M－":
                    memory -= num;
                    break;
                case "MS":
                    memory = decimal.Parse(numBox2.Text);
                    break;
            }
        }
    }
}
