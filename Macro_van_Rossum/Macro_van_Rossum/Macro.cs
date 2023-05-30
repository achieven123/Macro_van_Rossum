using System.Runtime.InteropServices;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Macro_van_Rossum
{
    public partial class Macro : Form
    {
        public List<Tuple<int, string, int, int>> list = new List<Tuple<int, string, int, int>>();

        [DllImport("user32.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern void mouse_event(int dwFlags, int dx, int dy, int cButtons, int dwExtraInfo);

        [DllImport("user32")]
        public static extern int SetCursorPos(int x, int y);

        private const int MouseLeftDown = 0x0002;
        private const int MouseLeftUp = 0x0004;
        private const int MouseRightDown = 0x0008;
        private const int MouseRightUp = 0x0010;

        public Macro()
        {
            InitializeComponent();

            // ReloadListBox();
        }

        private void Macro_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.ControlKey) OpenMouse();
            if (e.KeyCode == Keys.ShiftKey) OpenKeyboard();
        }

        private void MouseButton_Click(object sender, EventArgs e)
        {
            OpenMouse();
        }

        private void KeyboardButton_Click(object sender, EventArgs e)
        {
            OpenKeyboard();
        }

        private void DeleteButton_Click(object sender, EventArgs e)
        {
            int index = ListBox.SelectedIndex;

            if (list.Count == 0) return;

            if (index != -1)
            {
                list.RemoveAt(index);

                ReloadListBox();

                if (index != 0)
                {
                    ListBox.SelectedIndex = index - 1;
                }
            }
        }

        private void SettinglButton_Click(object sender, EventArgs e)
        {
            if (SettingButton.Text == "설정")
            {
                SettingButton.Text = "닫기";
                ResizeForm(518, 10, 1, 0);
            }
            else
            {
                SettingButton.Text = "설정";
                ResizeForm(315, 10, 1, 1);
            }
        }

        private void RunButton_Click(object sender, EventArgs e)
        {
            WindowState = FormWindowState.Minimized;

            for (int idx = 0; idx < list.Count; idx++)
            {
                int type = list[idx].Item1;
                if (type == 0) AutoMouseClick(idx);
                if (type == 1) AutoKeyboardInput(idx);
            }

            System.Threading.Thread.Sleep(1000);
            this.WindowState = FormWindowState.Normal;
        }

        public void OpenMouse()
        {
            this.WindowState = FormWindowState.Minimized;
            Mouse modal = new Mouse(list);
            modal.ShowDialog();
            ReloadListBox();
            this.WindowState = FormWindowState.Normal;
            ListBox.SelectedIndex = list.Count - 1;
        }

        public void MouseSetPosCustom(int x, int y)
        {
            try
            {
                SetCursorPos(x, y);
            }
            catch (Exception e)
            {
                MessageBox.Show("MouseSetPosCustom\r\n" + e.Message);
            }
        }

        public void AutoMouseClick(int idx)
        {
            string str = list[idx].Item2;
            int x = list[idx].Item3;
            int y = list[idx].Item4;

            MouseSetPosCustom(x, y);
            System.Threading.Thread.Sleep(100);

            if (str.Equals("Left"))
            {
                mouse_event(MouseLeftDown, 0, 0, 0, 0);
                System.Threading.Thread.Sleep(5);
                mouse_event(MouseLeftUp, 0, 0, 0, 0);
                System.Threading.Thread.Sleep(5);
            }
            else if (str.Equals("Right"))
            {
                mouse_event(MouseRightDown, 0, 0, 0, 0);
                System.Threading.Thread.Sleep(5);
                mouse_event(MouseRightUp, 0, 0, 0, 0);
                System.Threading.Thread.Sleep(5);
            }
        }

        public void OpenKeyboard()
        {
            int x = this.Location.X;
            int y = this.Location.Y;
            Keyboard modal = new Keyboard(list, x, y);
            modal.ShowDialog();
            ReloadListBox();
            ListBox.SelectedIndex = list.Count - 1;
        }

        public void AutoKeyboardInput(int idx)
        {
            string str = list[idx].Item2;

            SendKeys.Send($"{str}");
        }

        public void ReloadListBox()
        {
            ListBox.Items.Clear();

            for (int idx = 0; idx < list.Count; idx++)
            {
                int type = list[idx].Item1;
                string str = list[idx].Item2;
                int x = list[idx].Item3;
                int y = list[idx].Item4;

                if (type == 0)
                {
                    ListBox.Items.Add($"[{idx}] Mouse : {str}({x}, {y})");
                }
                else if (list[idx].Item1 == 1)
                {
                    ListBox.Items.Add($"[{idx}] Keyboard : {str}");
                }
            }
        }

        public void ResizeForm(int resizeWidth, int resizeSpeed, int delay, int change)
        {
            if (change == 0)
            {
                this.MaximumSize = new System.Drawing.Size(resizeWidth, this.Height);

                for (int x = this.Width; x <= resizeWidth; x += resizeSpeed)
                {
                    Size = new Size(x, this.Height);
                    System.Threading.Thread.Sleep(delay);
                }

                this.MinimumSize = new System.Drawing.Size(resizeWidth, this.Height);
            }
            else if (change == 1)
            {
                this.MinimumSize = new System.Drawing.Size(resizeWidth, this.Height);

                for (int x = this.Width; x >= resizeWidth; x -= resizeSpeed)
                {
                    Size = new Size(x, this.Height);
                    System.Threading.Thread.Sleep(delay);
                }

                this.MaximumSize = new System.Drawing.Size(resizeWidth, this.Height);
            }
        }
    }
}