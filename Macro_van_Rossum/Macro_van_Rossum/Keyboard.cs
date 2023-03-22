namespace Macro_van_Rossum
{
    public partial class Keyboard : Form
    {
        List<Tuple<int, string, int, int>> lists;

        public Keyboard(List<Tuple<int, string, int, int>> list, int x, int y)
        {
            InitializeComponent();

            this.Location = new Point(x + 400, y);
            lists = list;
        }

        private void AddButton_Click(object sender, EventArgs e)
        {
            AddKeyboard();
        }

        private void TextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter) AddKeyboard();
        }

        public void AddKeyboard()
        {
            string text = TextBox.Text;
            int type = 1;

            lists.Add(new Tuple<int, string, int, int>(type, text, 0, 0));

            this.Close();
        }
    }
}
