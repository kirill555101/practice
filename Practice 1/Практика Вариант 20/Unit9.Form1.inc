procedure InitializeComponent;
    begin
        self.button1 := new System.Windows.Forms.Button();
        self.maskedTextBox1 := new System.Windows.Forms.MaskedTextBox();
        self.label1 := new System.Windows.Forms.Label();
        self.SuspendLayout();
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(115, 104);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(112, 44);
        self.button1.TabIndex := 21;
        self.button1.Text := 'Ввод';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button1_Click;
        // 
        // maskedTextBox1
        // 
        self.maskedTextBox1.Location := new System.Drawing.Point(88, 54);
        self.maskedTextBox1.Name := 'maskedTextBox1';
        self.maskedTextBox1.Size := new System.Drawing.Size(171, 20);
        self.maskedTextBox1.TabIndex := 20;
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(88, 28);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(171, 23);
        self.label1.TabIndex := 19;
        self.label1.Text := 'Введите название города';
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(349, 198);
        self.Controls.Add(self.button1);
        self.Controls.Add(self.maskedTextBox1);
        self.Controls.Add(self.label1);
        self.Name := 'Form1';
        self.Text := 'Количество переписи населения';
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
