procedure InitializeComponent;
    begin
        self.pictureBox1 := new System.Windows.Forms.PictureBox();
        self.label1 := new System.Windows.Forms.Label();
        self.label2 := new System.Windows.Forms.Label();
        (System.ComponentModel.ISupportInitialize(self.pictureBox1)).BeginInit();
        self.SuspendLayout();
        // 
        // pictureBox1
        // 
        self.pictureBox1.Location := new System.Drawing.Point(12, 27);
        self.pictureBox1.Name := 'pictureBox1';
        self.pictureBox1.Size := new System.Drawing.Size(838, 509);
        self.pictureBox1.TabIndex := 1;
        self.pictureBox1.TabStop := false;
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(12, 9);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(196, 15);
        self.label1.TabIndex := 2;
        self.label1.Text := 'Количество выпущенных продуктов';
        self.label1.TextAlign := System.Drawing.ContentAlignment.BottomLeft;
        self.label1.Click += label1_Click;
        // 
        // label2
        // 
        self.label2.Location := new System.Drawing.Point(801, 539);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(49, 16);
        self.label2.TabIndex := 3;
        self.label2.Text := 'Год';
        self.label2.TextAlign := System.Drawing.ContentAlignment.TopRight;
        self.label2.Click += label2_Click;
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(862, 558);
        self.Controls.Add(self.label2);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.pictureBox1);
        self.Name := 'Form1';
        self.Text := 'График изменения количества выпущенных программ по годам';
        (System.ComponentModel.ISupportInitialize(self.pictureBox1)).EndInit();
        self.ResumeLayout(false);
    end;
