procedure InitializeComponent;
    begin
        self.button1 := new System.Windows.Forms.Button();
        self.maskedTextBox1 := new System.Windows.Forms.MaskedTextBox();
        self.label1 := new System.Windows.Forms.Label();
        self.SuspendLayout();
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(83, 106);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(112, 44);
        self.button1.TabIndex := 18;
        self.button1.Text := 'Ввод';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button3_Click;
        // 
        // maskedTextBox1
        // 
        self.maskedTextBox1.Location := new System.Drawing.Point(56, 56);
        self.maskedTextBox1.Mask := '00000';
        self.maskedTextBox1.Name := 'maskedTextBox1';
        self.maskedTextBox1.Size := new System.Drawing.Size(171, 20);
        self.maskedTextBox1.TabIndex := 17;
        self.maskedTextBox1.ValidatingType := typeof(System.Int32);
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(45, 30);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(199, 23);
        self.label1.TabIndex := 16;
        self.label1.Text := 'Введите год';
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(284, 162);
        self.Controls.Add(self.button1);
        self.Controls.Add(self.maskedTextBox1);
        self.Controls.Add(self.label1);
        self.Name := 'Form1';
        self.Text := 'Поиск по ОЗУ';
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
