namespace Macro_van_Rossum
{
    public partial class Mouse : Form
    {
        List<Tuple<int, string, int, int>> lists;

        public Mouse(List<Tuple<int, string, int, int>> list)
        {
            InitializeComponent();

            lists = list;

            this.WindowState = FormWindowState.Maximized;
        }

        private void Mouse_MouseClick(object sender, MouseEventArgs e)
        {
            int x = Convert.ToInt32(Cursor.Position.X.ToString());
            int y = Convert.ToInt32(Cursor.Position.Y.ToString());
            int type = 0;

            var click = (e.Button == MouseButtons.Left) ? "Left" : "Right";
            lists.Add(new Tuple<int, string, int, int>(type, click, x, y));
            this.Close();
        }
    }
}
