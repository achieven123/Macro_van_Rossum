using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Macro_van_Rossum
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            checkedListBox1.Items.Add("심리학1");
            checkedListBox1.Items.Add("심리학2");
            checkedListBox1.Items.Add("심리학3");
            checkedListBox1.Items.Add("심리학4");
            checkedListBox1.Items.Add("심리학5");
            checkedListBox1.Items.Add("심리학6");
        }
        private void button1_Click(object sender, EventArgs e)
        {
            foreach(var dept in checkedListBox1.CheckedItems)
            {
                listBox1.Items.Add(dept);
            }
        }

        List<String> removeList = new List<string>();
        private void button3_Click(object sender, EventArgs e)
        {
            foreach (var dept in checkedListBox1.SelectedItems)
            {
                removeList.ADD(dept);
            }

            listBox1.Items.Remove(dept);
        }
    }
}
