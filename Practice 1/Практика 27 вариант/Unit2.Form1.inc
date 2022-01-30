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
        self.maskedTextBox5 := new System.Windows.Forms.MaskedTextBox();
        self.label5 := new System.Windows.Forms.Label();
        self.SuspendLayout();
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(13, 56);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(154, 23);
        self.label1.TabIndex := 0;
        self.label1.Text := 'Введите название линии';
        // 
        // maskedTextBox1
        // 
        self.maskedTextBox1.Location := new System.Drawing.Point(13, 82);
        self.maskedTextBox1.Name := 'maskedTextBox1';
        self.maskedTextBox1.Size := new System.Drawing.Size(154, 20);
        self.maskedTextBox1.TabIndex := 1;
        self.maskedTextBox1.MaskInputRejected += maskedTextBox1_MaskInputRejected;
        // 
        // label2
        // 
        self.label2.Location := new System.Drawing.Point(13, 105);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(154, 23);
        self.label2.TabIndex := 2;
        self.label2.Text := 'Введите год открытия';
        // 
        // maskedTextBox2
        // 
        self.maskedTextBox2.Location := new System.Drawing.Point(12, 131);
        self.maskedTextBox2.Mask := '00000';
        self.maskedTextBox2.Name := 'maskedTextBox2';
        self.maskedTextBox2.Size := new System.Drawing.Size(154, 20);
        self.maskedTextBox2.TabIndex := 3;
        self.maskedTextBox2.ValidatingType := typeof(System.Int32);
        // 
        // label3
        // 
        self.label3.Location := new System.Drawing.Point(13, 154);
        self.label3.Name := 'label3';
        self.label3.Size := new System.Drawing.Size(154, 23);
        self.label3.TabIndex := 4;
        self.label3.Text := 'Введите длину в км';
        // 
        // maskedTextBox3
        // 
        self.maskedTextBox3.Location := new System.Drawing.Point(12, 180);
        self.maskedTextBox3.Mask := '00000';
        self.maskedTextBox3.Name := 'maskedTextBox3';
        self.maskedTextBox3.Size := new System.Drawing.Size(154, 20);
        self.maskedTextBox3.TabIndex := 5;
        self.maskedTextBox3.ValidatingType := typeof(System.Int32);
        // 
        // label4
        // 
        self.label4.Location := new System.Drawing.Point(12, 203);
        self.label4.Name := 'label4';
        self.label4.Size := new System.Drawing.Size(154, 23);
        self.label4.TabIndex := 6;
        self.label4.Text := 'Введите количество станций';
        self.label4.Click += label4_Click;
        // 
        // maskedTextBox4
        // 
        self.maskedTextBox4.Location := new System.Drawing.Point(12, 229);
        self.maskedTextBox4.Mask := '00000';
        self.maskedTextBox4.Name := 'maskedTextBox4';
        self.maskedTextBox4.Size := new System.Drawing.Size(154, 20);
        self.maskedTextBox4.TabIndex := 7;
        self.maskedTextBox4.ValidatingType := typeof(System.Int32);
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(12, 255);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(119, 45);
        self.button1.TabIndex := 8;
        self.button1.Text := 'Ввод';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button1_Click;
        // 
        // button2
        // 
        self.button2.Location := new System.Drawing.Point(188, 255);
        self.button2.Name := 'button2';
        self.button2.Size := new System.Drawing.Size(119, 45);
        self.button2.TabIndex := 9;
        self.button2.Text := 'Назад';
        self.button2.UseVisualStyleBackColor := true;
        self.button2.Click += button2_Click;
        // 
        // maskedTextBox5
        // 
        self.maskedTextBox5.Location := new System.Drawing.Point(12, 33);
        self.maskedTextBox5.Mask := '00000';
        self.maskedTextBox5.Name := 'maskedTextBox5';
        self.maskedTextBox5.Size := new System.Drawing.Size(154, 20);
        self.maskedTextBox5.TabIndex := 10;
        self.maskedTextBox5.ValidatingType := typeof(System.Int32);
        // 
        // label5
        // 
        self.label5.Location := new System.Drawing.Point(13, 7);
        self.label5.Name := 'label5';
        self.label5.Size := new System.Drawing.Size(154, 23);
        self.label5.TabIndex := 11;
        self.label5.Text := 'Введите номер линии';
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(319, 315);
        self.Controls.Add(self.label5);
        self.Controls.Add(self.maskedTextBox5);
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
