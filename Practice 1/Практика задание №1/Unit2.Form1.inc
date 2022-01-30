procedure InitializeComponent;
    begin
        self.label1 := new System.Windows.Forms.Label();
        self.maskedTextBox1 := new System.Windows.Forms.MaskedTextBox();
        self.label2 := new System.Windows.Forms.Label();
        self.maskedTextBox2 := new System.Windows.Forms.MaskedTextBox();
        self.label3 := new System.Windows.Forms.Label();
        self.maskedTextBox3 := new System.Windows.Forms.MaskedTextBox();
        self.label4 := new System.Windows.Forms.Label();
        self.maskedTextBox4 := new System.Windows.Forms.MaskedTextBox();
        self.button1 := new System.Windows.Forms.Button();
        self.button2 := new System.Windows.Forms.Button();
        self.SuspendLayout();
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(13, 12);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(154, 23);
        self.label1.TabIndex := 0;
        self.label1.Text := 'Введите название услуги';
        // 
        // maskedTextBox1
        // 
        self.maskedTextBox1.Location := new System.Drawing.Point(13, 38);
        self.maskedTextBox1.Name := 'maskedTextBox1';
        self.maskedTextBox1.Size := new System.Drawing.Size(154, 20);
        self.maskedTextBox1.TabIndex := 1;
        self.maskedTextBox1.MaskInputRejected += maskedTextBox1_MaskInputRejected;
        // 
        // label2
        // 
        self.label2.Location := new System.Drawing.Point(13, 70);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(154, 23);
        self.label2.TabIndex := 2;
        self.label2.Text := 'Введите фамилию мастера';
        // 
        // maskedTextBox2
        // 
        self.maskedTextBox2.Location := new System.Drawing.Point(13, 96);
        self.maskedTextBox2.Name := 'maskedTextBox2';
        self.maskedTextBox2.Size := new System.Drawing.Size(154, 20);
        self.maskedTextBox2.TabIndex := 3;
        // 
        // label3
        // 
        self.label3.Location := new System.Drawing.Point(13, 131);
        self.label3.Name := 'label3';
        self.label3.Size := new System.Drawing.Size(154, 23);
        self.label3.TabIndex := 4;
        self.label3.Text := 'Введите срок выполения';
        // 
        // maskedTextBox3
        // 
        self.maskedTextBox3.Location := new System.Drawing.Point(13, 157);
        self.maskedTextBox3.Name := 'maskedTextBox3';
        self.maskedTextBox3.Size := new System.Drawing.Size(154, 20);
        self.maskedTextBox3.TabIndex := 5;
        // 
        // label4
        // 
        self.label4.Location := new System.Drawing.Point(13, 192);
        self.label4.Name := 'label4';
        self.label4.Size := new System.Drawing.Size(154, 23);
        self.label4.TabIndex := 6;
        self.label4.Text := 'Введите стоиость в рублях';
        self.label4.Click += label4_Click;
        // 
        // maskedTextBox4
        // 
        self.maskedTextBox4.Location := new System.Drawing.Point(13, 218);
        self.maskedTextBox4.Name := 'maskedTextBox4';
        self.maskedTextBox4.Size := new System.Drawing.Size(154, 20);
        self.maskedTextBox4.TabIndex := 7;
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(13, 258);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(119, 45);
        self.button1.TabIndex := 8;
        self.button1.Text := 'Ввод';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button1_Click;
        // 
        // button2
        // 
        self.button2.Location := new System.Drawing.Point(157, 258);
        self.button2.Name := 'button2';
        self.button2.Size := new System.Drawing.Size(119, 45);
        self.button2.TabIndex := 9;
        self.button2.Text := 'Назад';
        self.button2.UseVisualStyleBackColor := true;
        self.button2.Click += button2_Click;
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(290, 315);
        self.Controls.Add(self.button2);
        self.Controls.Add(self.button1);
        self.Controls.Add(self.maskedTextBox4);
        self.Controls.Add(self.label4);
        self.Controls.Add(self.maskedTextBox3);
        self.Controls.Add(self.label3);
        self.Controls.Add(self.maskedTextBox2);
        self.Controls.Add(self.label2);
        self.Controls.Add(self.maskedTextBox1);
        self.Controls.Add(self.label1);
        self.Name := 'Form1';
        self.Text := 'Добавление данных';
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
